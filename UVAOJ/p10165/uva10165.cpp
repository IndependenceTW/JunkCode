#include <iostream>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }

        int ex_or;

        cin >> ex_or;

        for (int i = 1; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            ex_or = ex_or xor tmp;
        }

        if (ex_or == 0)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
    return 0;
}