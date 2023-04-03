#include <iostream>
using namespace std;
const int N = 10;
class MyArray {
    private:
        int x[N];
    public:
        MyArray(int *_x){
            for (int i = 0; i < N; i ++) x[i] = _x[i];
        }
        void Disp() {
            for (int i = 0; i < N; i ++) cout << x[i] << " ";
            cout << '\n';
        }
        bool operator== (int *t) {
            for (int i = 0; i < N; i ++)
                if (x[i] != t[i]) return false;
            return true;
        }
        MyArray& operator+ (int t) {
            for (int i = 0; i < N; i ++) x[i] += t;
            return *this;
        }
        MyArray& operator= (int *t) {
            for (int i = 0; i < N; i ++) x[i] = t[i];
            return *this;
        }
        MyArray& operator++ () {
            for (int i = 0; i < N; i ++) x[i] ++;
            return *this;
        }
        MyArray operator++ (int) {
            MyArray old = *this;
            ++(*this);
            return old;
        }
        int& operator[] (int idx) {
            return x[idx];
        }
};
int main() {
    int arr1[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    MyArray t1(arr1);
    if (t1 == arr1) cout << "True" << '\n';
    else cout << "False" << '\n';
    t1 = t1 + 5; t1.Disp();
    ++ t1; t1.Disp();
    t1[0] = 1; t1.Disp();
    
    int arr2[N] = {6, 5, 1, 32, 48, 9, 6, 1, 6, 32};
    MyArray t2(arr2);
    if (t2 == arr2) cout << "True" << '\n';
    else cout << "False" << '\n';
    t2 = t2 + 10; t2.Disp();
    ++ t2; t2.Disp();
    t2[0] = 5; t2.Disp();
    
    int arr3[N] = {9, 8, 74, 6, 51, 32, 12, 36, 5, 4};
    MyArray t3(arr3);
    if (t3 == arr3) cout << "True" << '\n';
    else cout << "False" << '\n';
    t3 = t3 + 1; t3.Disp();
    ++ t3; t3.Disp();
    t3[0] = 10; t3.Disp();
    
    return 0;
}