#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> coordinates;
const int INFIN = 0x3f3f;
const int MAX_SIZE = 1000;
int m[MAX_SIZE][MAX_SIZE];
int shortest[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];

struct compare {
    bool operator()(coordinates a, coordinates b) {
        return shortest[a.first][a.second] > shortest[b.first][b.second];
    }
};
priority_queue<coordinates, vector<coordinates>, compare> pq;

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        int rows;
        int columns;
        cin >> rows >> columns;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                cin >> m[i][j];
                // pq.push({i, j});
            }
        }
        
        memset(shortest, INFIN, sizeof(shortest));
        memset(visited, 0, sizeof(visited));
        shortest[0][0] = m[0][0];
        pq.push({0,0});
        visited[0][0] = 1;

        while(!pq.empty()) {
            coordinates now = pq.top();
            int x = now.first;
            int y = now.second;
            // cout << x << " " << y << endl;
            // cout << shortest[x][y] << endl;
            
            // top
            if(x - 1 >= 0) {
                shortest[x - 1][y] = min(shortest[x][y] + m[x - 1][y], shortest[x - 1][y]);
                if(!visited[x-1][y]) {
                    pq.push({x - 1, y});
                    visited[x-1][y] = 1;
                }
            }
            // down
            if(x + 1 < rows) {
                shortest[x + 1][y] = min(shortest[x][y] + m[x + 1][y], shortest[x + 1][y]);
                if(!visited[x+1][y]) {
                    pq.push({x+1,y});
                    visited[x+1][y] = 1;
                }
            }
            // left
            if(y - 1 >= 0) {
                shortest[x][y - 1] = min(shortest[x][y] + m[x][y - 1], shortest[x][y - 1]);
                if(!visited[x][y - 1]){
                    pq.push({x, y-1});
                    visited[x][y - 1] = 1;
                }
            }
            // right
            if(y + 1 < columns) {
                shortest[x][y + 1] = min(shortest[x][y] + m[x][y + 1], shortest[x][y + 1]);
                if(!visited[x][y + 1]){
                    pq.push({x, y + 1});
                    visited[x][y + 1] = 1;
                }
            }
            pq.pop();
            // cout << "--------------------------------" << endl;
            // for(int i = 0; i < rows; i++) {
            //     for(int j = 0; j < columns; j++) {
            //         cout << shortest[i][j] << ' ';
            //     }
            //     cout << endl;
            // }
            // cout << "--------------------------------" << endl;
        }
        

        cout << shortest[rows-1][columns-1] << endl;
    }
    return 0;
}