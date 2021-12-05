#include<bits/stdc++.h>

using namespace std;

const int maxn = 0x3f;

int dp[3][1001];
int a[5010];

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        int k, n;
        cin >> k >> n;
        k+=8;
        for(int i = n; i > 0; i--) {
            cin >> a[i];
        }
        memset(dp, maxn, sizeof(dp));
        
        dp[0][0] = 0;
        dp[1][0] = 0;
        dp[2][0] = 0;

        for(int i = 3; i <= n; i++) {
            for(int j = 1; j * 3 <= i; j ++) {
                dp[i%3][j] = min(dp[(i-1)%3][j], dp[(i-2)%3][j-1]+(a[i] - a[i-1]) * (a[i] - a[i - 1]));
            }
        }

        cout << dp[n%3][k] << endl;
    }
    return 0;
}