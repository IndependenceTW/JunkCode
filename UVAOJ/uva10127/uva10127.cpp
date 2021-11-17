#include <iostream>

using namespace std;

int main()
{
    int x;
    while (cin >> x)
    {
        int count = 1;
        int modN = 1;

        while (modN % x != 0)
        {
            modN = modN % x * 10 + 1;
            count++;
        }

        cout << count << endl;
    }
    return 0;
}