#include <iostream>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    cin.ignore();
    while (cases--)
    {
        string target;
        int tests;
        getline(cin, target);
        cin >> tests;
        cin.ignore();
        while (tests--)
        {
            string cmp;
            getline(cin, cmp);

            //fail
            int fail[cmp.size()];
            int point = -1; //for create the fail array
            fail[0] = -1;
            for (int i = 1; i < cmp.size(); i++)
            {
                while (point >= 0 && cmp.at(point + 1) != cmp.at(i))
                {
                    point = fail[point];
                }
                if (cmp.at(point + 1) == cmp.at(i))
                {
                    point++;
                }
                fail[i] = point;
            }

            //campare to array
            int pt = 0;
            int pc = 0;

            while (pt < target.size() && pc < cmp.size())
            {
                if (target.at(pt) == cmp.at(pc))
                {
                    pt++;
                    pc++;
                }
                else
                {
                    if (fail[pc - 1] == -1)
                    {
                        pt++;
                        pc = 0;
                    }
                    else
                    {
                        pc = fail[pc - 1] + 1;
                    }
                }
            }

            if (pc == cmp.size())
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