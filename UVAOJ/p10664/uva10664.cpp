#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// first number represent the number of package
// second number represent the max of package
int m[201][201];

bool canBalanced(vector<int> p, int total)
{
    if (total % 2 == 1)
    {
        return false;
    }
    else
    {
        int max_size = p.size();
        int avg = total / 2;
        for (int i = 0; i <= max_size; i++)
        {
            m[0][i] = 0;
        }
        for (int i = 0; i <= avg; i++)
        {
            m[i][0] = 0;
        }
        for (int i = 1; i <= max_size; i++)
        {
            for (int w = 1; w <= avg; w++)
            {
                if (p.at(i - 1) > w)
                {
                    m[i][w] = m[i - 1][w];
                }
                else
                {
                    m[i][w] = max(m[i - 1][w], m[i - 1][w - p.at(i - 1)] + p.at(i - 1));
                }
            }
        }

        // for (int i = 0; i <= max_size; i++)
        // {
        //     for (int w = 0; w <= avg; w++)
        //     {
        //         cout << ' ' << m[i][w];
        //     }
        //     cout << endl;
        // }

        return avg == m[max_size][avg];
    }
}

int main()
{
    int m;
    string s;
    cin >> m;
    getline(cin, s);
    for (int i = 0; i < m; i++)
    {
        vector<int> package;
        int tmp;
        int total = 0;
        getline(cin, s);
        stringstream sin(s);

        while (sin >> tmp)
        {
            total += tmp;
            package.push_back(tmp);
        }

        sort(package.begin(), package.end());

        if (canBalanced(package, total))
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