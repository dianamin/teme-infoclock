/*
    http://www.infoarena.ro/problema/zeul
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ifstream f ("zeul.in");
ofstream g ("zeul.out");

const int NMAX = 100000 + 1;

int n, m;
pair <int, int> grad[NMAX];
vector < pair <int, int> > sol;


void init() {
    for (int i = 1; i <= n; i++)
        grad[i].second = i;
}

void citeste() {
    f >> n >> m;

    int a, b;
    for (int i = 1; i <= m; i++) {
        f >> a >> b;
        grad[a].first++;
        grad[b].first--;
    }
}

void rezolva() {
    int j = n, m;
    pair <int, int> p;

    for (int i = 1; grad[i].first != 0; i++) {
        while (grad[i].first != 0) {
            m = min(-grad[i].first, grad[j].first);

            p.first = grad[i].second;
            p.second = grad[j].second;

            for (int k = 1; k <= m; k++) sol.push_back(p);

            grad[i].first += m;
            grad[j].first -= m;
            if (grad[j].first == 0) j--;
        }
    }
}

void scrie() {
    int nr_sol = sol.size();

    g << nr_sol << '\n';
    for (int i = 0; i < nr_sol; i++)
        g << sol[i].first << ' ' << sol[i].second << '\n';
}

int main() {
    citeste();
    init();
    sort(grad + 1, grad + n + 1);
    rezolva();
    scrie();
    return 0;
}
