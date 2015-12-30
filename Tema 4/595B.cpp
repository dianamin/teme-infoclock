/*
    http://codeforces.com/contest/595/problem/B
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("date.in");

const int MOD = 1000000000 + 7;
const int NMAX = 100000 + 1;

int n, k, d;
long long a[NMAX], b[NMAX];

void citeste() {
    cin >> n >> k;

    d = n / k;
    for (int i = 1; i <= d; i++) cin >> a[i];
    for (int i = 1; i <= d; i++) cin >> b[i];
}

inline int divizibile(long long n, int k) {
    //de la 0 la n - 1;
    return n / k + (n % k != 0);
}

void rezolva() {
    long long nr_total = 1, nr = 0;

    long long p = 1;
    for (int i = 1; i <= k; i++) p *= 10;

    for (int i = 1; i <= d; i++) {
        //cout << (b[i] + 1) * p / 10 << ' ' << b[i] * p / 10 << endl;
        nr = divizibile(p, a[i]) - divizibile((b[i] + 1) * p / 10, a[i]) + divizibile(b[i] * p / 10, a[i]);
        //cout << nr << endl;
        nr_total = (nr_total * nr) % MOD;
    }

    cout << nr_total << '\n';
}

int main() {
    citeste();
    rezolva();
    return 0;
}
