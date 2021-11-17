#include <iostream>

using namespace std;

int coin[1000];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> coin[i];
        }

        int sum = coin[0];
        int ans = 2;
        for (int i = 1; i < n - 1; i++)
        {
            if (sum < coin[i] && sum + coin[i] < coin[i + 1])
            {
                sum += coin[i];
                ans++;
            }
        }

        cout << ans << endl;
    }
    return 0;
}