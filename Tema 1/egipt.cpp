/*
    http://www.infoarena.ro/problema/egipt
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream f ("egipt.in");
ofstream g ("egipt.out");

const int VALMAX = 3 + 1;
const int NMAX = 10000 + 1;

int n;
int cnt[VALMAX];
int v[NMAX];

vector < pair <int, int> > sol;

void citeste() {
    f >> n;
    for (int i = 1; i <= n; i++) {
        f >> v[i];
        cnt[v[i]]++;
    }
}

void rezolva() {
    int start1 = 1, sfarsit1 = cnt[1];
    int start2 = cnt[1] + 1, sfarsit2 = cnt[2] + cnt[1];
    int start3 = cnt[2] + cnt[1] + 1, sfarsit3 = n;

    int i1 = start1, i2 = start2, i3 = start3;

    while (v[i2] != 1 && i2 <= sfarsit2) i2++;
    while (v[i3] != 1 && i3 <= sfarsit3) i3++;


    while (i1 <= sfarsit1) {
        while (v[i1] == 1 && i1 <= sfarsit1) i1++;
        if (i1 > sfarsit1) break;

        if ((v[i1] == 2 && i2 <= sfarsit2) || (v[i1] == 3 && i3 > sfarsit3)) {
            swap(v[i1], v[i2]);
            sol.push_back(make_pair(i1, i2));
            i2++;
            while (v[i2] != 1 && i2 <= sfarsit2) i2++;
        }
        else {
            swap(v[i1], v[i3]);
            sol.push_back(make_pair(i1, i3));
            i3++;
            while (v[i3] != 1 && i3 <= sfarsit3) i3++;
        }

        i1++;
    }

    i2 = start2;
    i3 = start3;
    while (v[i3] != 2 && i3 <= sfarsit3) i3++;

    while (i2 <= sfarsit2) {
        while(v[i2] == 2 && i2 <= sfarsit2) i2++;

        if (i2 > sfarsit2) break;
        swap(v[i2], v[i3]);
        sol.push_back(make_pair(i2, i3));
        i3++;
        while (v[i3] != 2 && i3 <= sfarsit3) i3++;
        i2++;
    }
}

void scrie() {
    int l = sol.size();

    g << l << '\n';
    for (int i = 0; i < l; i++)
        g << sol[i].first << ' ' << sol[i].second << '\n';
}

int main() {
    citeste();
    rezolva();
    scrie();
    return 0;
}
