#include <iostream>
#include <string>

using namespace std;

int arr[1000001];

int main()
{
    string s;
    int cases = 1;
    while (cin >> s)
    {
        int test;
        int group = 0;
        cin >> test;
        for (int i = 0; i < s.size(); i++)
        {
            arr[i] = 0;
        }
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] != s[i - 1])
            {
                arr[i] = ++group;
            }
            else
            {
                arr[i] = group;
            }
        }

        cout << "Case " << cases++ << ":" << endl;
        for (int i = 0; i < test; i++)
        {
            int m, n;
            cin >> m >> n;
            if (arr[m] == arr[n])
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}