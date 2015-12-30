/*
    http://codeforces.com/contest/585/problem/A
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream f ("date.in");

const int NMAX = 4000 + 1;

int n;
bool a_plecat[NMAX];
int v[NMAX], d[NMAX], p[NMAX];
vector <int> sol;
queue <int> Q;

void citeste() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> d[i] >> p[i];
}

void rezolva() {
    for (int i = 1; i <= n; i++) {
        if (a_plecat[i] == true) continue;
        sol.push_back(i);
        int k = v[i];

        for (int j = i + 1; j <= n && k; j++) {
            if (a_plecat[j] == true) continue;

            p[j] -= k;
            k--;

            if (p[j] < 0) {
                Q.push(j);
                a_plecat[j] = true;
            }
        }

        while (!Q.empty()) {
            int x = Q.front();
            Q.pop();
            for (int j = x + 1; j <= n; j++) {
                if (a_plecat[j]) continue;
                p[j] -= d[x];
                if (p[j] < 0) {
                    a_plecat[j] = true;
                    Q.push(j);
                }
            }
        }
    }
}

void scrie() {
    int l = sol.size();
    cout << l << '\n';
    for (int i = 0; i < l; i++)
        cout << sol[i] << ' ';
}

int main() {
    citeste();
    rezolva();
    scrie();
    return 0;
}
