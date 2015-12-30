/*
    http://www.infoarena.ro/problema/random
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("random.in");
ofstream g ("random.out");

void show_winner(int year) {
    if (year == 1982) g << "Robert Tarjan";
    else if (year == 1986) g << "Leslie Valiant";
    else if (year == 1990) g << "Alexander Razborov";
    else if (year == 1994) g << "Avi Wigderson";
    else if (year == 1998) g << "Peter Shor";
    else if (year == 2002) g << "Madhu Sudan";
    else if (year == 2006) g << "Jon Kleinberg";
    else if (year == 2010) g << "Daniel Spielman";
    else g << "Subhash Khot";

    g << '\n';
}

int main() {
    int year;
    f >> year;
    show_winner(year);
    return 0;
}

