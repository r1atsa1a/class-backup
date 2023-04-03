#include <iostream>
using namespace std;
template<class T>
class MyVector {
    T *x;
    int len, cap;
    public:
        MyVector() {
            x = NULL;
            len = 0;
            cap = 0;
        }
        MyVector(T *_x, int _len) {
            len = _len;
            cap = 2 * _len;
            x = new int[cap];
            for (int i = 0; i < len; i ++)
                x[i] = _x[i];
        }
        MyVector(const MyVector<T>& _t) {
            if (x) delete x;
            len = _t.len;
            cap = 2 * _t.len;
            x = new int[cap];
            for (int i = 0; i < len; i ++)
                x[i] = _t.x[i];
        }
        ~MyVector() {
            delete x;
        }
        void Push_Back(T elem) {
            x[len ++] = elem;
        }
        void Pop_Back() {
            len --;
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
    MyVector<int> t1(arr1, n1);
    int n2 = 5, arr2[5] = {0, 1, 2, 3, 4};
    MyVector<int> t2(arr2, n2);
    t1.Disp();
    t1.Push_Back(10);
    t1.Disp();
    t1 = t2;
    t1.Disp();
    cout << "T1[1] = " << t1[1] << '\n';
}