#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

typedef struct package package;
struct package
{
    int id;
    int price;
    int a;
    int b;
    int c;
    int d;
};
package pack[60];

bool cmp(package a, package b)
{
    return a.id < b.id;
}

int main()
{
    int n;
    string buffer;
    char status;

    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            int inte, fl;
            cin >> pack[i].id;
            scanf("%d.%d", &inte, &fl);
            pack[i].price = inte * 100 + fl;
            getline(cin, buffer);
            pack[i].a = 0;
            pack[i].b = 0;
            pack[i].c = 0;
            pack[i].d = 0;

            istringstream sin(buffer);
            while (sin >> status)
            {
                int num;
                sin >> num;
                if (status == 'a')
                {
                    pack[i].a = num;
                }
                if (status == 'b')
                {
                    pack[i].b = num;
                }
                if (status == 'c')
                {
                    pack[i].c = num;
                }
                if (status == 'd')
                {
                    pack[i].d = num;
                }
            }
        }

        sort(pack, pack + n, cmp);

        int t;
        cin >> t;
        cin.ignore();
        for (int i = 1; i <= t; i++)
        {
            getline(cin, buffer);
            istringstream sin(buffer);
            int n_a = 0, n_b = 0, n_c = 0, n_d = 0;

            while (sin >> status)
            {
                int num;
                sin >> num;
                if (status == 'a')
                {
                    n_a += num;
                }
                if (status == 'b')
                {
                    n_b += num;
                }
                if (status == 'c')
                {
                    n_c += num;
                }
                if (status == 'd')
                {
                    n_d += num;
                }
            }
            int dp[n_a + 1][n_b + 1][n_c + 1][n_d + 1];

            for (int j = 0; j <= n_a; j++)
            {
                for (int k = 0; k <= n_b; k++)
                {
                    for (int l = 0; l <= n_c; l++)
                    {
                        for (int m = 0; m <= n_d; m++)
                        {
                            dp[j][k][l][m] = 10000000;
                        }
                    }
                }
            }

            dp[0][0][0][0] = 0;

            for (int o = 0; o < n; o++)
            {
                for (int j = 0; j <= n_a; j++)
                {
                    for (int k = 0; k <= n_b; k++)
                    {
                        for (int l = 0; l <= n_c; l++)
                        {
                            for (int m = 0; m <= n_d; m++)
                            {
                                dp[j][k][l][m] = min(dp[j][k][l][m], dp[max(j - pack[o].a, 0)][max(k - pack[o].b, 0)][max(l - pack[o].c, 0)][max(m - pack[o].d, 0)] + pack[o].price);
                            }
                        }
                    }
                }
            }

            int buyAmount[n] = {0};
            int trace_back = 0;
            int nowA = n_a, nowB = n_b, nowC = n_c, nowD = n_d;
            while (trace_back < n)
            {
                int tempA = nowA - pack[trace_back].a;
                int tempB = nowB - pack[trace_back].b;
                int tempC = nowC - pack[trace_back].c;
                int tempD = nowD - pack[trace_back].d;
                if (tempA < 0)
                {
                    tempA = 0;
                }
                if (tempB < 0)
                {
                    tempB = 0;
                }
                if (tempC < 0)
                {
                    tempC = 0;
                }
                if (tempD < 0)
                {
                    tempD = 0;
                }
                if (dp[nowA][nowB][nowC][nowD] - dp[tempA][tempB][tempC][tempD] - pack[trace_back].price == 0)
                {
                    buyAmount[trace_back]++;
                    nowA = tempA, nowB = tempB, nowC = tempC, nowD = tempD;
                }
                else
                {
                    trace_back++;
                }
            }

            printf("%d:%8.2f", i, dp[n_a][n_b][n_c][n_d] / 100.0);
            for (int j = 0; j < n; j++)
            {
                if (buyAmount[j] == 0)
                {
                    continue;
                }
                cout << ' ' << pack[j].id;
                if (buyAmount[j] > 1)
                {
                    cout << '(' << buyAmount[j] << ')';
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}