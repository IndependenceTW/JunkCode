#include <iostream>
#include <cmath>

using namespace std;

int digit(int n)
{
    int count = 0;
    while (n > 0)
    {
        n /= 10;
        count++;
    }

    return count;
}

int main()
{
    int n;
    while (cin >> n)
    {
        int k = digit(n) + 1;

        while (1)
        {
            int lower = (int)(log2(n) + k * log2(10));
            int upper = (int)(log2(n + 1) + k * log2(10));
            if (lower != upper)
            {
                cout << upper << endl;
                break;
            }
            k++;
        }
    }
    return 0;
}