#include <iostream>

using namespace std;

int pile[10000];

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }

        for (int i = 0; i < n; i++)
        {
            cin >> pile[i];
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            ans = ans ^ pile[i];
        }

        if (ans)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}