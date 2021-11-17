#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
int total_w;
int weight[101];
ll dp[100 * 450];

void input()
{
    total_w = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
        total_w += weight[i];
    }
}

void do_dp()
{
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int w = total_w / 2; w >= weight[i]; w--)
        {
            dp[w] = (dp[w - weight[i]] << 1) | dp[w];
        }
    }
}

void output()
{
    int i;
    if (n & 1)
    {
        for (i = total_w / 2; i >= 0; i--)
        {
            ll flag1 = (1ll << (n / 2));
            ll flag2 = (1ll << (n / 2 + 1));
            if ((dp[i] & flag1) || (dp[i] & flag2))
                break;
        }
    }
    else
    {
        for (i = total_w / 2; i >= 0; i--)
        {
            if (dp[i] & (1ll << (n / 2)))
            {
                break;
            }
        }
    }
    cout << min(i, total_w - i) << ' ' << max(i, total_w - i) << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        input();
        do_dp();
        output();
        if (t)
            cout << endl;
    }
    return 0;
}