#include <bits/stdc++.h>
#define MAX_VALUE 10000000

using namespace std;

vector<int> adj_list[MAX_VALUE];
int isVisited[MAX_VALUE]; // -1 not used 0 used 1 visited
int inDegree[MAX_VALUE];

void add_edge(int from, int to)
{
    isVisited[from] = 0;
    isVisited[to] = 0;
    inDegree[to]++;
    adj_list[from].push_back(to);
}

bool bfs(int r)
{
    queue<int> q;
    q.push(r);
    while (!q.empty())
    {
        int f = q.front();
        if (isVisited[f] == 0)
        {
            isVisited[f] = 1;
        }
        else
        {
            return false;
        }
        for (int i = 0; i < adj_list[f].size(); i++)
        {
            q.push(adj_list[f].at(i));
        }
        q.pop();
    }
    return true;
}

int main()
{
    int cases = 1;
    int from, to;
    while (scanf("%d%d", &from, &to))
    {
        bool isTree = true;
        int root = -1;

        if (from < 0 && to < 0)
        {
            break;
        }
        for (int i = 0; i < MAX_VALUE; i++)
        {
            adj_list[i].clear();
            isVisited[i] = -1;
            inDegree[i] = 0;
        }

        while (from != 0 && to != 0)
        {
            add_edge(from, to);
            scanf("%d%d", &from, &to);
        }

        for (int i = 0; i < MAX_VALUE; i++)
        {
            if (isVisited[i] == -1)
            {
                continue;
            }
            if (inDegree[i] == 0 && root == -1)
            {
                root = i;
            }
            else if (inDegree[i] == 0)
            {
                isTree = false;
            }
            else if (inDegree[i] > 1)
            {
                isTree = false;
            }
        }

        isTree = isTree && bfs(root);

        for (int i = 0; i < MAX_VALUE; i++)
        {
            if (isVisited[i] == 0)
            {
                isTree = false;
            }
        }

        if (isTree)
        {
            printf("Case %d is a tree.\n", cases);
        }
        else
        {
            printf("Case %d is not a tree.\n", cases);
        }

        cases++;
    }
    return 0;
}