/*
    http://codeforces.com/contest/595/problem/A
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("date.in");

int main() {
    int n, m, a, b, sol = 0;

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a >> b;
            sol = sol + (a + b > 0);
        }

    cout << sol << '\n';
    return 0;
}
