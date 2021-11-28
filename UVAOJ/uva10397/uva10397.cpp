#include<bits/stdc++.h>

using namespace std;

typedef struct Coordinate Coordinate;
struct Coordinate {
    int x;
    int y;
};

struct Edge{
    int node1;
    int node2;
    double distance;
};

int disjoint_set[751];
Coordinate location[751];
vector<Edge> edge;
double size;

int Find(int);
void Union(int, int, double);
double Distance(Coordinate, Coordinate);
void CreateEdge(int);
bool cmp(Edge, Edge);

int main() {
    int n;
    int m;
    while(cin >> n) {
        for(int i = 0; i <= n; i++) {
            disjoint_set[i] = i;
            location[i].x = 0;
            location[i].y = 0;
        }
        size = 0;

        for(int i = 1; i <= n; i++) {
            cin >> location[i].x >> location[i].y;
        }

        CreateEdge(n);
        cin >> m;
        for(int i = 0; i < m; i++) {
            int node1;
            int node2;
            cin >> node1 >> node2;
            Union(node1, node2, 0);
        }
        sort(edge.begin(), edge.end(), cmp);
        for(int i = 0; i < edge.size(); i++) {
            int node1 = edge.at(i).node1;
            int node2 = edge.at(i).node2;
            double distance = edge.at(i).distance;
            Union(node1, node2, distance);
        }
        
        printf("%.02lf\n", size);

        edge.clear();
    }
    return 0;
}

int Find(int node) {
    if(disjoint_set[node] != node) {
        disjoint_set[node] = Find(disjoint_set[node]);
    }

    return disjoint_set[node];
}

void Union(int node1, int node2, double dis) {
    int root1 = Find(node1);
    int root2 = Find(node2);

    if(root1 != root2) {
        disjoint_set[root1] = root2;
        size += dis;
    }
}

double Distance(Coordinate node1, Coordinate node2) {
    int xx = (node1.x - node2.x) * (node1.x - node2.x);
    int yy = (node1.y - node2.y) * (node1.y - node2.y);

    return sqrt(xx+yy);
}

void CreateEdge(int n){
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            Edge tmp;
            tmp.node1 = i;
            tmp.node2 = j;
            tmp.distance = Distance(location[i], location[j]);
            edge.push_back(tmp);
        }
    }
}

bool cmp(Edge v1, Edge v2) {
    return v1.distance < v2.distance;
}