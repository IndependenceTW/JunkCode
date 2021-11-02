#include <iostream>
#include <string>

using namespace std;

int ds[26];
int groups;

int find(int i)
{
    return i == ds[i] ? i : ds[i] = find(ds[i]);
}

void uni(int i, int j)
{
    i = find(i);
    j = find(j);
    if (i != j)
    {
        ds[i] = j;
        groups--;
    }
}

int main()
{
    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        char largestChar;
        string input;
        cin >> largestChar;
        getline(cin, input);
        groups = largestChar - 'A' + 1;

        for (int i = 0; i < groups; i++)
        {
            ds[i] = i;
        }

        while (getline(cin, input))
        {
            if (input.size() == 0)
            {
                break;
            }
            uni(input.at(0) - 'A', input.at(1) - 'A');
        }

        cout << groups << endl;
        if (i != cases - 1)
        {
            cout << endl;
        }
    }
    return 0;
}