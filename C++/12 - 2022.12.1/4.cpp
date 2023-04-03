#include <iostream>
#include <set>
using namespace std;
int main() {
    set<double> ist1;
    for (int i = 1; i <= 10; i ++) {
        ist1.insert(rand() % 50 * 1.1);
    }
    for (set<double>::iterator it = ist1.begin(); it != ist1.end(); ++ it) cout << *it << " ";
    cout << '\n';
    set<double> ist2;
    for (int i = 1; i <= 10; i ++) {
        ist2.insert(rand() % 50 * 1.1);
    }
    for (set<double>::iterator it = ist2.begin(); it != ist2.end(); ++ it) cout << *it << " ";
    cout << '\n';
    set<double> ist3;
    for (int i = 1; i <= 10; i ++) {
        ist3.insert(rand() % 50 * 1.1);
    }
    for (set<double>::iterator it = ist3.begin(); it != ist3.end(); ++ it) cout << *it << " ";
    cout << '\n';
    return 0;
}