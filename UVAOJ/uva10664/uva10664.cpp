#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m;
    cin >> m;
    cin.ignore();
    while (m--)
    {
        string buf;
        vector<int> luggage;
        int tmp;
        int half = 0;

        getline(cin, buf);
        istringstream sin(buf);

        while (sin >> tmp)
        {
            half += tmp;
            luggage.push_back(tmp);
        }

        int size = luggage.size();

        if (half % 2 == 1)
        {
            cout << "NO" << endl;
            continue;
        }
        half /= 2;

        sort(luggage.begin(), luggage.end());
        int dp[size + 1][half + 1];

        for (int i = 0; i <= size; i++)
        {
            dp[i][0] = 0;
        }

        for (int i = 0; i <= half; i++)
        {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= size; i++)
        {
            for (int j = 1; j <= half; j++)
            {
                if (j - luggage.at(i - 1) < 0)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - luggage.at(i - 1)] + luggage.at(i - 1));
                }
            }
        }

        if (dp[size][half] == half)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}