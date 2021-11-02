#include <iostream>
#include <algorithm>
#define MAX_VALUE 1001

using namespace std;

int cost[MAX_VALUE];

int main()
{
    while (true)
    {
        int n;
        int avg = 0;
        int payMore;
        int sol = 0;

        cin >> n;
        if (n <= 0)
        {
            break;
        }

        for (int i = 0; i < n; i++)
        {
            int integer, decent;
            scanf("%d.%d", &integer, &decent);
            cost[i] = integer * 100 + decent;
            avg += cost[i];
        }

        payMore = avg % n;
        avg /= n;
        sort(cost, cost + n, greater<int>());

        for (int i = 0; i < payMore; i++)
        {
            sol += abs(cost[i] - avg - 1);
        }
        for (int i = payMore; i < n; i++)
        {
            sol += abs(cost[i] - avg);
        }
        sol /= 2;

        printf("$%d.%02d\n", sol / 100, sol % 100);
    }
    return 0;
}