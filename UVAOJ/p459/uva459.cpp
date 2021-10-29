#include <iostream>
#define MAX_VALUE 101

using namespace std;

class Node
{
public:
    // construction
    Node(char c)
    {
        data = c;
        next = nullptr;
    };

    // data
    char data;
    Node *next;
};

Node *graph[MAX_VALUE];

bool isFound(char c, Node *target)
{
    Node *now = target;
    while (now != nullptr)
    {
        if (now->data == c)
        {
            return true;
        }
        else
        {
            now = now->next;
        }
    }
    return false;
}

void merge(char c, char d, char large)
{
    int max = large - 'A';
    int find_c = -1;
    int find_d = -1;

    for (int i = 0; i <= max; i++)
    {
        if (isFound(c, graph[i]))
        {
            find_c = i;
        }
        if (isFound(d, graph[i]))
        {
            find_d = i;
        }

        if (find_c != -1 && find_d != -1)
        {
            break;
        }
    }

    if (find_c == find_d)
    {
        return;
    }
    else
    {
        Node *now = graph[find_c];
        Node *tmp = graph[find_d];
        graph[find_d] = nullptr;

        while (now->next != nullptr)
        {
            now = now->next;
        }
        now->next = tmp;
    }
}

int main()
{
    int num;
    string s, blank;
    char large_c;

    cin >> num;
    for (int i = 0; i < num; i++)
    {
        int ans = 0;

        // read the blank line

        // first line read the node, the largest node
        cin >> large_c;
        for (char c = 'A'; c <= large_c; c++)
        {
            graph[c - 'A'] = new Node(c);
        }
        getline(cin, blank);

        // read the edge
        while (getline(cin, s) && !s.empty())
        {
            merge(s.at(0), s.at(1), large_c);
        }

        //count
        for (int i = 0; i <= (int)(large_c - 'A'); i++)
        {
            if (graph[i] != nullptr)
            {
                ans++;
            }
        }
        cout << ans << endl;
        if (i != num - 1)
        {
            cout << endl;
        }
    }

    return 0;
}