#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

const string END_OF_GRAMMAR = "END_OF_GRAMMAR";

vector<char> nonterminals;
map<char, string> rules;
map<char, set<char>> first_set;

void input();
vector<string> split(string, char);
void find_1st(char);
bool is_terminal(char);

int main()
{
    input();

    for (int i = 0; i < nonterminals.size(); i++)
    {
        char nont = nonterminals.at(i);
        if (first_set.find(nont) == first_set.end())
        {
            find_1st(nont);
        }
    }

    sort(nonterminals.begin(), nonterminals.end());

    for (int i = 0; i < nonterminals.size(); i++)
    {
        char nont = nonterminals.at(i);
        cout << nont << ' ';
        for (set<char>::iterator it = first_set[nont].begin(); it != first_set[nont].end(); it++)
        {
            cout << *it;
        }
        cout << endl;
    }
    cout << "END_OF_FIRST" << endl;

    return 0;
}

void find_1st(char tok)
{
    set<char> first;
    if (is_terminal(tok))
    {
        first.insert(tok);
    }
    else
    {
        vector<string> rule_list = split(rules[tok], '|');
        for (int i = 0; i < rule_list.size(); i++)
        {
            int head_index = 0;
            char head;
            set<char> tmp;
            do
            {
                head = rule_list[i][head_index++];
                if (first_set.find(head) == first_set.end())
                {
                    find_1st(head);
                }
                tmp.insert(first_set[head].begin(), first_set[head].end());
                if (tmp.find(';') != tmp.end())
                {
                    tmp.erase(';');
                }
            } while (first_set[head].find(';') != first_set[head].end() && head_index < rule_list[i].size());
            //printf("%c: %c %d\n", tok, head, head_index);
            if (first_set[head].find(';') != first_set[head].end() && head_index == rule_list[i].size())
            {
                tmp.insert(';');
            }
            first.insert(tmp.begin(), tmp.end());
        }
    }

    first_set[tok] = first;
}

bool is_terminal(char t)
{
    if (t <= 'Z' && t >= 'A')
    {
        return false;
    }
    return true;
}

vector<string> split(string s, char c)
{
    vector<string> pieces;
    string tmp;
    for (int i = 0; i < s.size(); i++)
    {
        char now = s.at(i);
        if (now == c)
        {
            pieces.push_back(tmp);
            tmp.clear();
        }
        else
        {
            tmp.push_back(now);
        }
    }
    pieces.push_back(tmp);
    return pieces;
}

void input()
{
    string input;
    while (getline(cin, input))
    {
        if (input == END_OF_GRAMMAR)
        {
            break;
        }
        char left = input.at(0);
        int space_index = input.find(' ');
        string right = input.substr(space_index + 1);

        nonterminals.push_back(left);
        rules[left] = right;
    }
}
