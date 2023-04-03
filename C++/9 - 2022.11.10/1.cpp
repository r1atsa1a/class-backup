#include <iostream>
using namespace std;
class MyInt {
    private:
        int x;
    public:
        MyInt(int _x = 0) : x(_x) {}
        void Disp() {
            cout << "X = " << x << '\n';
        }
        bool operator== (int t) {
            if (x == t) return true;
            else return false;
        }
        MyInt operator+ (int t) {
            return MyInt(x + t);
        }
        MyInt operator+ (MyInt t) {
            return MyInt(x + t.x);
        }
        MyInt& operator= (int t) {
            x += t;
            return *this;
        }
        MyInt& operator++ () {
            x ++;
            return *this;
        }
        MyInt operator++ (int) {
            MyInt old = *this;
            ++(*this);
            return old;
        }
};
int main() {
    MyInt t1_1(1), t1_2;
    if (t1_1 == 1) cout << "True" << '\n';
    else cout << "False" << '\n';
    t1_2 = t1_1 + 1; t1_2.Disp();
    ++t1_1; t1_1.Disp();
    t1_1++; t1_1.Disp();

    MyInt t2_1(1), t2_2;
    if (t2_1 == 2) cout << "True" << '\n';
    else cout << "False" << '\n';
    t2_2 = t2_1 + t2_1; t2_2.Disp();
    ++t2_1; t2_1.Disp();
    t2_1++; t2_1.Disp();

    MyInt t3_1(5), t3_2;
    if (t3_1 == 5) cout << "True" << '\n';
    else cout << "False" << '\n';
    t3_2 = t3_1 + 5; t3_2.Disp();
    ++t3_1; t3_1.Disp();
    t3_1++; t3_1.Disp();
    
    return 0;
}