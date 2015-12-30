/*
    http://www.infoarena.ro/problema/trenul
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("trenul.in");
ofstream g ("trenul.out");

int n, m;

void rezolva() {
    int loc_sus = 1, loc_jos = n;
    int oameni;

    while(m--) {
        f >> oameni;
        if (oameni % 2 == 0) {
            for (int i = oameni; i >= 1; i--)
                g << loc_jos - i + 1 << ' ';
            loc_jos -= oameni;
        }
        else {
            for (int i = 1; i <= oameni; i++) {
                g << loc_sus << ' ';
                loc_sus++;
            }
        }
        g << '\n';
    }
}

int main() {
    f >> n >> m;
    rezolva();
    return

