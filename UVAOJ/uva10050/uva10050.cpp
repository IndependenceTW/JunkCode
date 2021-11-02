#include <iostream>

using namespace std;

int days[3650];

int main()
{
    int test;
    cin >> test;
    for (int i = 0; i < test; i++)
    {
        int num;
        int cases;
        int sum = 0;
        cin >> num >> cases;
        for (int i = 0; i < num; i++)
        {
            days[i] = 0;
        }

        for (int i = 0; i < cases; i++)
        {
            int k;
            cin >> k;
            for (int i = k - 1; i < num; i += k)
            {
                if (i % 7 == 5 || i % 7 == 6)
                {
                    continue;
                }
                days[i] = 1;
            }
        }

        for (int i = 0; i < num; i++)
        {
            sum += days[i];
        }

        cout << sum << endl;
    }

    return 0;
}