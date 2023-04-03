#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
class Test {
    public:
        int a, b;
        char c;
        Test(int _a, int _b, char _c) {a = _a; b = _b; c = _c;}
        Test() {a = 1; b = 2; c = 'c';}
        ~Test() {}
};
int main() {
    char c;
    Test t1(2, 3, 'a'), t2(4, 5, 'b'), t3(6, 7, 'c'), c1;
    ofstream ofs("3.txt", ios::out);
    ofs << t1.c << " " << t1.a << " " << t1.b << '\n';
    ofs << t2.c << " " << t2.a << " " << t2.b << '\n';
    ofs << t3.c << " " << t3.a << " " << t3.b << '\n';
    ifstream ifs("3.txt", ios::in);
    for (int i = 0; i < 3; i++) {
        ifs >> c1.c >> c1.a >> c1.b;
        cout << c1.a << " " << c1.b << " " << c1.c << '\n';
    }
    return 0;
}