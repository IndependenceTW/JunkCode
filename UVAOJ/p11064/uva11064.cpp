#include <iostream>
#define MAX 150000

using namespace std;

typedef unsigned int ui;

ui fac[32], num[32];
ui prim[MAX];
int used[MAX];

int main()
{
    ui save = 0;
    ui n;
    // count the prim
    for (ui i = 0; i < MAX; i++)
    {
        used[i] = 0;
    }

    for (ui i = 2; i < MAX; i++)
    {
        if (used[i] == 0)
        {
            prim[save++] = i;
            for (ui j = i * 2; j < MAX; j += i)
            {
                used[j] = 1;
            }
        }
    }

    while (cin >> n)
    {

        ui counter = 0;
        ui base = 0;
        ui m = n;
        ui ans = m;
        ui f = 1;

        while (n > 1 && base < save)
        {
            if (n % prim[base] == 0)
            {
                fac[counter] = prim[base];
                num[counter] = 0;
                while (n % prim[base] == 0)
                {
                    n /= prim[base];
                    num[counter]++;
                }
                counter++;
            }
            base++;
        }

        if (n > 1)
        {
            fac[counter] = n;
            num[counter] = 1;
            counter++;
        }

        // euler function
        for (ui i = 0; i < counter; i++)
        {
            ans = ans / fac[i] * (fac[i] - 1);
        }

        // factor numbers
        for (ui i = 0; i < counter; i++)
        {
            f = f * (num[i] + 1);
        }

        cout << m - ans - f + 1 << endl;
    }

    return 0;
}
