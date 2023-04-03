#include <iostream>
using namespace std;
const int M = 2, N = 3;
class MyMatrix {
    private:
        int x[M][N];
    public:
        MyMatrix(int _x[M][N]) {
            for (int i = 0; i < M; i ++)
                for (int j = 0; j < N; j ++)
                    x[i][j] = _x[i][j];
        }
        void Disp() {
            for (int i = 0; i < M; i ++) {
                for (int j = 0; j < N; j ++)
                    cout << x[i][j] << " ";
                cout << '\n';
            }
        }
        bool operator!= (int t[M][N]) {
            for (int i = 0; i < M; i ++)
                for (int j = 0; j < N; j ++)
                    if (x[i][j] != t[i][j]) return false;
            return true;
        }
        MyMatrix& operator- (int t) {
            for (int i = 0; i < M; i ++)
                for (int j = 0; j < N; j ++)
                    x[i][j] -= t;
            return *this;
        }
        MyMatrix& operator= (int t[M][N]) {
            for (int i = 0; i < M; i ++)
                for (int j = 0; j < N; j ++)
                    x[i][j] = t[i][j];
            return *this;
        }
        MyMatrix& operator-- () {
            for (int i = 0; i < M; i ++)
                for (int j = 0; j < N; j ++)
                    x[i][j] --;
            return *this;
        }
        MyMatrix operator-- (int) {
            MyMatrix old = *this;
            --(*this);
            return old;
        }
};
int main() {
    int arr1[M][N] = {{0, 1, 2}, {3, 4, 5}};
    MyMatrix t1(arr1);
    if (t1 != arr1) cout << "False" << '\n';
    else cout << "True" << '\n';
    t1 = t1 - 1; t1.Disp();
    -- t1; t1.Disp();

    int arr2[M][N] = {{50, 14, 72}, {31, 48, 57}};
    MyMatrix t2(arr2);
    if (t2 != arr2) cout << "False" << '\n';
    else cout << "True" << '\n';
    t2 = t2 - 5; t2.Disp();
    -- t2; t2.Disp();
    
    int arr3[M][N] = {{22, 11, 27}, {73, 46, 53}};
    MyMatrix t3(arr3);
    if (t3 != arr3) cout << "False" << '\n';
    else cout << "True" << '\n';
    t3 = t3 - 12; t3.Disp();
    -- t3; t3.Disp();

    return 0;
}