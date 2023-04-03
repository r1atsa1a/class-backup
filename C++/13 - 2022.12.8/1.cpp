#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int main() {
    int a = 8, a1;
    double b = 12.2, b1;
    char c[10] = "asdf", c1[10];
    ofstream ofs;
    ofs.open("1.txt", ios::trunc);
    ofs << a << " " << b << " " << c << '\n';
    ifstream ifs("1.txt", ios::in);
    ifs >> a1 >> b1 >> c1;
    cout << a1 << " " << b1 << " " << c1 << '\n';
    return 0;
}