#include <iostream>
using namespace std;
template<class T>
class MyArr {
    public:
        T *x;
        int len;
        MyArr(T *_x, int _len) {
            len = _len;
            x = new int[_len];
            for (int i = 0; i < _len; i ++)
                x[i] = _x[i];
        }
        MyArr(const MyArr<T>& _t) {
            if (x) delete x;
            len = _t.len;
            x = new int[_t.len];
            for (int i = 0; i < _t.len; i ++)
                x[i] = _t.x[i];
        }
        ~MyArr() {
            delete x;
        }
        MyArr& operator =(MyArr _t) {
            if (x) delete x;
            len = _t.len;
            x = new int[_t.len];
            for (int i = 0; i < _t.len; i ++)
                x[i] = _t.x[i];
            return *this;
        }
        bool operator ==(MyArr _t) {
            if (len != _t.len) return false;
            for (int i = 0; i < _t.len; i ++)
                if (x[i] != _t.x[i]) return false;
            return true;
        }
        T& operator [](int idx) {
            return x[idx];
        }
        void Disp() {
            for (int i = 0; i < len; i ++)
                cout << x[i] << " ";
            cout << '\n';
        }
};
int main() {
    int n1 = 10, arr1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    MyArr<int> t1(arr1, n1);
    int n2 = 5, arr2[5] = {0, 1, 2, 3, 4};
    MyArr<int> t2(arr2, n2);
    if (t1 == t2) cout << "T1 = T2" << '\n';
    else cout << "T1 != T2" << '\n';
    t1.Disp();
    t1 = t2;
    t1.Disp();
    cout << "T1[1] = " << t1[1] << '\n';
}