/*
    http://codeforces.com/contest/593/problem/A
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

ifstream f ("date.in");

const int ALPHA = 26;
const int NMAX = 100 + 1;
const int LENMAX = 1000 + 1;

int n;
int sol;
char s[LENMAX];
int len_max[ALPHA][ALPHA];

void rezolva() {
    int lungime, nr_litere;
    pair <int, int> litere;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        lungime = strlen(s);

        sort(s, s + lungime);

        nr_litere = 1;
        litere.first = s[0] - 'a';

        for (int j = 1; j < lungime; j++)
            if (s[j] != s[j - 1]) {
                nr_litere++;
                litere.second = s[j] - 'a';
            }

        if (nr_litere > 2) continue;

        if (nr_litere == 1) {
            for (litere.second = 0; litere.second < ALPHA; litere.second++) {
                len_max[litere.first][litere.second] += lungime;
                sol = max(sol, len_max[litere.first][litere.second]);
                if (litere.first == litere.second) continue;
                len_max[litere.second][litere.first] += lungime;
                sol = max(sol, len_max[litere.second][litere.first]);
            }
        }
        else {
            len_max[litere.first][litere.second] += lungime;
            sol = max(sol, len_max[litere.first][litere.second]);
            len_max[litere.second][litere.first] += lungime;
            sol = max(sol, len_max[litere.second][litere.first]);
        }
    }
}



int main() {
    rezolva();
    cout << sol << '\n';
    return 0;
}
