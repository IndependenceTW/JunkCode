#include <bits/stdc++.h>

using namespace std;

int x[101];
int y[101];

int main() {
    int n;

    while (cin >> n) {
        if (n == 0) break;
        int flag = 1;
        memset (x, 0, sizeof(x));
        memset (y, 0, sizeof(y));
        for (int i = 0; i < 2 * n; i++) {
            cin >> x[i] >> y[i];
        }

        for (int i = -500; flag && i <= 500; i++) {
            for (int j = -500; flag && j <= 500; j++) {
                int big = 0;
                int small = 0;
                
                for (int k = 0; k < 2 * n; k++) {
                    //ix + jy
                    int fuc = i * x[k] + j * y[k];
                    if (fuc > 0) big++;
                    if (fuc < 0) small++;
                }

                if (big == n && small == n) {
                    cout << i << " " << j << endl;
                    flag = 0;
                }
            }
        }
        
    }
    return 0;
}