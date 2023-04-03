#include <iostream>
using namespace std;
const int M = 10;
template<class T, class P>
class Sample {
    public:
        T x;
        P y;
        Sample(T _x, P _y) : x(_x), y(_y) {}
        Sample(const Sample<T, P>& _t) : x(_t.x), y(_t.y) {}
        Sample& operator =(Sample _t) {
            x = _t.x;
            y = _t.y;
            return *this;
        }
        bool operator ==(Sample _t) {
            if (x == _t.x && y == _t.y) return true;
            return false;
        }
        Sample operator +(Sample _t) {
            x += _t.x;
            y += _t.y;
            return Sample(x, y);
        }
        Sample& operator ++() {
            x ++;
            y ++;
            return *this;
        }
        Sample& operator ++(int) {
            Sample old = *this;
            ++(*this);
            return old;
        }
        void Disp() {
            cout << "X = " << x << '\n';
            cout << "Y = " << y << '\n';
        }
};
int main() {
    Sample<int, double> t1(10, 5.00), t2(5, 10.00);
    if (t1 == t2) cout << "T1 = T2" << '\n';
    else cout << "T1 != T2" << '\n';
    t1 = t1 + t2; t1.Disp();
    ++ t1; t1.Disp();
    Sample<int, int> t3(2, 3), t4(2, 3);
    if (t3 == t4) cout << "T3 = T4" << '\n';
    else cout << "T3 != T4" << '\n';
    t3 = t3 + t4; t3.Disp();
    ++ t3; t3.Disp();
    return 0;
}