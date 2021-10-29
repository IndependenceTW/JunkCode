/*假解*/

#include <iostream>

using namespace std;

bool isSub(string s, string sub)
{
    int now_index = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s.at(i) == sub.at(now_index))
        {
            now_index++;
            if (now_index >= sub.size())
            {
                return true;
            }
        }
        else
        {
            now_index = 0;
        }
    }

    return false;
}

int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        string s;
        string sub;
        int q;
        cin >> s;
        cin >> q;
        for (int j = 0; j < q; j++)
        {
            cin >> sub;
            if (isSub(s, sub))
            {
                cout << 'y' << endl;
            }
            else
            {
                cout << 'n' << endl;
            }
        }
    }
    return 0;
}