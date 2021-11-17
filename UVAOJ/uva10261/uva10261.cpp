#include <bits/stdc++.h>

using namespace std;

int dp[2006][10001];
int length[2006];
int sum[2006];

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int capa;
        int numcar = 0;
        int maxCar = 0;
        int maxLoad = 0;
        int input;

        cin >> capa;
        capa *= 100;
        while (cin >> input)
        {
            if (input == 0)
            {
                break;
            }
            length[++numcar] = input;
        }

        sum[0] = 0;
        for (int i = 1; i <= numcar; i++)
        {
            sum[i] = sum[i - 1] + length[i];
        }

        for (int i = 0; i <= numcar; i++)
        {
            for (int j = 0; j <= capa; j++)
            {
                dp[i][j] = 0;
            }
        }

        dp[0][0] = 1;

        for (int i = 1; i <= numcar; i++)
        {
            for (int j = 0; j <= capa; j++)
            { //push left side and put right side
                if ((j - length[i] >= 0 && dp[i - 1][j - length[i]] == 1) || (capa - (sum[i - 1] - j) >= length[i] && dp[i - 1][j] == 1))
                {
                    dp[i][j] = 1;
                    maxCar = i;
                    maxLoad = j;
                }
            }
        }

        cout << maxCar << endl;

        stack<string> howTo;
        while (maxCar != 0 || maxLoad != 0)
        {
            if (dp[maxCar - 1][maxLoad - length[maxCar]] == 1)
            {
                howTo.push("port");

                maxLoad -= length[maxCar];
                maxCar--;
            }
            else if (dp[maxCar - 1][maxLoad] == 1)
            {
                howTo.push("starboard");
                maxCar--;
            }
            else
            {
                howTo.push("Tracebackerror");
                break;
            }
        }
        while (!howTo.empty())
        {
            cout << howTo.top() << endl;
            howTo.pop();
        }

        if (cases)
        {
            cout << endl;
        }
    }
    return 0;
}