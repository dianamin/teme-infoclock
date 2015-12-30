/*
    http://www.infoarena.ro/problema/buget
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream f ("buget.in");
ofstream g ("buget.out");

const int NMAX = 100000 + 1;

int n;
long long buget;
long long pret[NMAX];
long long suma[NMAX];

void citeste() {
    f >> n;
    f >> buget;
    for (int i = 1; i <= n; i++)
        f >> pret[i];
}

void sume_partiale() {
    for (int i = 1; i <= n; i++) suma[i] = suma[i - 1] + pret[i];
}

long long bani_cheltuiti(long long pret_maxim) {
    long long st = 1, dr = n, m, sol = 0;

    while (st <= dr) {
        m = (st + dr) / 2;

        if (pret[m] <= pret_maxim) {
            sol = m;
            st = m + 1;
        }
        else dr = m - 1;
    }

    return suma[sol] + pret_maxim * (n - sol);
}


void rezolva() {
    long long st = 1, dr = buget, m, sol = 1;

    while (st <= dr) {
        m = (st + dr) / 2;

        if (bani_cheltuiti(m) <= buget) {
            sol = m;
            st = m + 1;
        }
        else dr = m - 1;
    }

    g << sol << '\n';
}


int main() {
    citeste();
    sort(pret + 1, pret + n + 1);
    sume_partiale();

    rezolva();

    return 0;
}
