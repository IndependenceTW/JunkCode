#include <bits/stdc++.h>

using namespace std;

int weight[40];
int dp[666][666];

int find_distance(int j, int k, int total)
{
    return max(j, max(k, total - j - k)) - min(j, min(k, total - j - k));
}

int main()
{
    int c;
    cin >> c;
    for (int a = 1; a <= c; a++)
    {
        int n;
        int total = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> weight[i];
            total += weight[i];
        }

        for (int j = 0; j <= total; j++)
        {
            for (int k = 0; k <= total; k++)
            {
                dp[j][k] = 0;
            }
        }

        dp[0][0] = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = total; j >= 0; j--)
            {
                for (int k = total; k >= 0; k--)
                {
                    if (dp[j][k] == 1)
                    {
                        dp[j + weight[i]][k] = 1;
                        dp[j][k + weight[i]] = 1;
                    }
                }
            }
        }

        int ans = total;

        for (int j = 0; j <= total; j++)
        {
            for (int k = 0; k <= total; k++)
            {
                if (dp[j][k] == 1)
                {
                    ans = min(ans, find_distance(j, k, total));
                }
            }
        }

        printf("Case %d: %d\n", a, ans);
    }

    return 0;
}