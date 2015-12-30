/*
    http://www.infoarena.ro/problema/licenta
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream f ("licenta.in");
ofstream g ("licenta.out");

const int NMAX = 100000 + 1;

int n, m, k;
pair <int, int> mihaela[NMAX], decan[NMAX];

void citeste_timp(int &n, pair <int, int> v[]) {
    f >> n;

    for (int i = 1; i <= n; i++) {
        f >> v[i].first >> v[i].second;
        if (v[i].second - v[i].first < k) {
            i--; n--;
        }
    }
}

void citeste() {
    f >> k;

    citeste_timp(n, mihaela);
    citeste_timp(m, decan);
}

inline int lungime_intersectie(pair <int, int> a, pair <int, int> b) {
    return min(a.second, b.second) - max(a.first, b.first);
}

void rezolva() {
    sort(mihaela + 1, mihaela + n + 1);
    sort(decan + 1, decan + m + 1);


    int i, j;

    for (i = 1, j = 1; i <= n && j <= m;) {
        while (i <= n && mihaela[i].second <= decan[j].first) i++;
        while (j <= m && decan[j].second <= mihaela[i].first) j++;

        if (lungime_intersectie(mihaela[i], decan[j]) >= k) {
            g << max(mihaela[i].first, decan[j].first) << ' ' << max(mihaela[i].first, decan[j].first) + k << '\n';
            return;
        }

        if (mihaela[i].second < decan[j].second) i++;
        else j++;
    }
}

int main() {
    citeste();
    rezolva();
    return 0;
}
