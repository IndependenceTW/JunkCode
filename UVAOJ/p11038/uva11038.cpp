#include <iostream>

using namespace std;

long long int sum0(long long int n) {
    long long int N = n;
    long long int sum = 0;
    long long int last;
    long long int div = 1;

    while (N >= 10) {
        last = N % 10;
        N /= 10;

        if (last == 0)
            sum += ((N - 1) * div + n % div + 1);
        else
            sum += N * div;

        div *= 10;
    }

    return sum;
}

int count0(long long int lli) {
    long long int div;
    int times = 0;
    while (lli >= 10) {
        if (lli % 10 == 0) times++;
        lli /= 10;
    }
    return times;
}

int main() {
    long long int m;
    long long int n;

    while (cin >> m >> n) {
        if (m < 0) break;

        long long int sol = sum0(n) - sum0(m);

        sol += count0(m);

        cout << sol << endl;
    }

    return 0;
}