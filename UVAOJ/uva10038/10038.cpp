#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int lasted;
        int now;
        bool isJolly = true;
        set<int> jolly;
        //first case
        cin >> lasted;
        for (int i = 1; i < n; i++)
        {
            cin >> now;
            if (!isJolly)
            {
                continue;
            }
            int a = abs(now - lasted);
            if (a >= n)
            {
                isJolly = false;
            }
            else if (jolly.count(a) == 1)
            {
                isJolly = false;
            }
            else
            {
                jolly.insert(a);
                lasted = now;
            }
        }
        if (isJolly)
        {
            cout << "Jolly" << endl;
        }
        else
        {
            cout << "Not jolly" << endl;
        }
    }
    return 0;
}