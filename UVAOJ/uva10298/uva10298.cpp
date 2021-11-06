#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        int size = s.size();
        if (s == ".")
        {
            break;
        }

        int fail[size];
        fail[0] = -1;
        int point = -1;
        for (int i = 1; i < size; i++)
        {
            while (point >= 0 && s.at(point + 1) != s.at(i))
            {
                point = fail[point];
            }
            if (s.at(point + 1) == s.at(i))
            {
                point++;
            }
            fail[i] = point;
        }

        int repeat = size - fail[size - 1] - 1;
        if (size % repeat == 0)
        {
            cout << size / repeat << endl;
        }
        else
        {
            cout << 1 << endl;
        }
    }
    return 0;
}