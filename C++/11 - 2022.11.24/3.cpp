#include <iostream>
using namespace std;
const int M = 10;
template<class T>
class Sample {
    public:
        T x[M];
        int len;
        Sample(T _x[], int _n) {
            len = _n;
            for (int i = 0; i < _n; i ++)
                x[i] = _x[i];
        }
        Sample(const Sample<T>& _t) {
            len = _t.len;
            for (int i = 0; i < _t.len; i ++)
                x[i] = _t.x[i];
        }
        Sample& operator =(Sample _t) {
            len = _t.len;
            for (int i = 0; i < _t.len; i ++)
                x[i] = _t.x[i];
            return *this;
        }
        bool operator ==(Sample _t) {
            if (len != _t.len) return false;
            for (int i = 0; i < _t.len; i ++)
                if (x[i] != _t.x[i]) return false;
            return true;
        }
        Sample operator +(Sample _t) {
            int TmaxLen = max(len, _t.len);
            int TminLen = min(len, _t.len);
            T Tarr[TmaxLen];
            for (int i = 0; i < TminLen; i ++)
                Tarr[i] = x[i] + _t.x[i];
            for (int i = TminLen; i < TmaxLen; i ++)
                if (len > _t.len) Tarr[i] = x[i];
                else Tarr[i] = _t.x[i];
            return Sample(Tarr, TmaxLen);
        }
        Sample& operator ++() {
            for (int i = 0; i < len; i ++)
                x[i] ++;
            return *this;
        }
        Sample& operator ++(int) {
            Sample old = *this;
            ++(*this);
            return old;
        }
        void Disp() {
            for (int i = 0; i < len; i ++)
                cout << x[i] << " ";
            cout << '\n';
        }
};
int main() {
    int n1 = 10, arr1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Sample<int> t1(arr1, n1);
    int n2 = 5, arr2[5] = {0, 1, 2, 3, 4};
    Sample<int> t2(arr2, n2);
    if (t1 == t2) cout << "T1 = T2" << '\n';
    else cout << "T1 != T2" << '\n';
    t1 = t1 + t2; t1.Disp();
    ++ t1; t1.Disp();
    return 0;
}