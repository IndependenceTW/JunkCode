#include <iostream>

using namespace std;

int main()
{
    int k, n;
    cin >> k;
    for (int j = 0; j < k; j++)
    {
        cin >> n;
        cin.ignore();
        string target[n], source[n];
        for (int i = 0; i < n; i++)
        {
            getline(cin, source[i]);
        }
        for (int i = 0; i < n; i++)
        {
            getline(cin, target[i]);
        }
        int pt, ps;
        pt = n - 1;
        ps = n - 1;
        while (ps >= 0)
        {
            if (target[pt] == source[ps])
            {
                pt--;
            }
            ps--;
        }
        while (pt >= 0)
        {
            cout << target[pt] << endl;
            pt--;
        }
        cout << endl;
    }
    return 0;
}