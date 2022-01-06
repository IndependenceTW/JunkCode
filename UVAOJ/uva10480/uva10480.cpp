/*
* Not writen by myself
* reference: https://blog.csdn.net/qq_43680965/article/details/106790346
*/

#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100;
const int INF = 0x3f3f3f3f;
int graph[MAXN][MAXN];
int flow[MAXN][MAXN];
int path[MAXN];
int a[MAXN];

int n, m, u[MAXN * 6], v[MAXN * 6], w;

int maxflow(int, int);

int main() {
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;

        memset(graph, 0, sizeof(graph));
        for(int i = 1; i <= m; i++) {
            cin >> u[i] >> v[i] >> w;
            graph[u[i]][v[i]] = graph[v[i]][u[i]] = w;
        }
        maxflow(1, 2);
        for (int i = 1; i <= m; i++) {
            if (a[u[i]] && !a[v[i]] || !a[u[i]] && a[v[i]]) {
                printf("%d %d\n", u[i], v[i]);
            }
        }
        printf("\n");
    }
    return 0;
}

int maxflow(int start, int end) {
    queue<int> q;
    memset(flow, 0, sizeof(flow));
    int max_flow = 0;
    while(true) {
        memset(a, 0, sizeof(a));
        a[start] = INF;
        
        while(!q.empty()) q.pop();
        q.push(start);
        
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            if(u == end) break;
            
            for(int v = 1; v <= n ; v++) {
                if (!a[v] && flow[u][v] < graph[u][v]) {
                    path[v] = u;
                    a[v] = min(a[u], graph[u][v] - flow[u][v]);
                    q.push(v);
                }
            }
        }

        if (a[end] == 0) break;

        for (int u = end; u != start; u = path[u]) {
            flow[path[u]][u] += a[end];
            flow[u][path[u]] -= a[end];
        }
        max_flow += a[end];
    }

    return max_flow;
}