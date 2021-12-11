#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

const string END_GRAMMAR = "END_OF_GRAMMAR";
const string END_FIRST = "END_OF_FIRST_SET";
map<char, vector<string> > rules;
map<char, set<char> > first_set;
map<char, set<char> > follow_set;
vector<char> nonterminals;

vector<string> split(string, char);
void input_grammar();
void input_first();
bool is_terminal();
set<char> find_first_set(char);
void find_follow_set();

int main() {
    input_grammar();
    input_first();
    find_follow_set();
    sort(nonterminals.begin(), nonterminals.end());
    for(int i = 0; i < nonterminals.size(); i++) {
        char c = nonterminals[i];

        cout << c << ' ';
        for(set<char>::iterator it = follow_set[c].begin(); it != follow_set[c].end(); it++) {
            cout << *it;
        }
        cout << endl;
    }


    return 0;
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

void input_grammar() {
    string input;
    while(getline(cin, input)) {
        if(input == END_GRAMMAR) {
            break;
        }

        char lhs = input.at(0);
        string rhs = input.substr(2, input.length()-1);
        vector<string> production = split(rhs, '|');
        
        nonterminals.push_back(lhs);
        rules[lhs] = production;
    }

}

void input_first() {
    string input;
    while(getline(cin, input)) {
        if(input == END_FIRST) {
            break;
        }
        
        char nont = input.at(0);
        set<char> first;
        for(int i = 2; i < input.length(); i++) {
            first.insert(input.at(i));
        }
        first_set[nont] = first;
    }

}

bool is_terminal(char c) {
    return !(c >= 'A' && c <= 'Z');
}

set<char> find_first_set(char c) {
    set<char> first;
    if(is_terminal(c)) {
        first.insert(c);
    }
    else {
        first = first_set[c];
    }
    return first;
}

void find_follow_set() {
    
    int save_size = 1;
    int certain_size = 1;
    follow_set[nonterminals[0]].insert('$');
    do{
        save_size = certain_size;
        for(int i = 0; i < nonterminals.size(); i++){
            char now_nt = nonterminals[i];
            for(int j = 0; j < rules[now_nt].size(); j++) {
                string now_rule = rules[now_nt][j];
                for(int k = 0; k < now_rule.length(); k++) {
                    if(!is_terminal(now_rule[k])) {
                        char b = now_rule[k];
                        for(int l = k + 1; l < now_rule.length(); l++) {
                            set<char> first_c = find_first_set(now_rule[l]);
                            follow_set[b].insert(first_c.begin(), first_c.end());
                            follow_set[b].erase(';');
                            if(first_c.find(';') == first_c.end()) {
                                break;
                            }
                        }
                        bool need_first = true;
                        for(int l = k + 1; l < now_rule.length(); l++) {
                            set<char> first_c = find_first_set(now_rule[l]);
                            need_first = need_first & (first_c.find(';') != first_c.end());
                            if(!need_first) {
                                break;
                            }
                        }
                        if(need_first) {
                            follow_set[b].insert(follow_set[now_nt].begin(), follow_set[now_nt].end());
                        }
                    }
                }
            }
        }
        certain_size = 0;
        for(int i = 0; i < nonterminals.size(); i++) {
            certain_size += follow_set[nonterminals[i]].size();
        }

    }while(save_size != certain_size);
}