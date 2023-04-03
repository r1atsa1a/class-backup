#include <iostream>
using namespace std;
const int M = 2, N = 3;
class Array {
    public:
        Array(double (*_arr)[N]) {
            ptr = new double[M][N];
            for (int i = 0; i < M; i ++)
                for (int j = 0; j < N; j ++)
                    *(*(ptr + i) + j) = _arr[i][j];
        }
        ~Array() {
            delete[] ptr;
        }
        double averVal() {
            double t = 0;
            for (int i = 0; i < M; i ++)
                for (int j = 0; j < N; j ++)
                    t += *(*(ptr + i) + j);
            return t / (M * N);
        }
    private:
        double (*ptr)[N];
};
int main() {
    double t1[M][N] = {{0, 1, 2}, {3, 4, 5}};
    Array A1(t1);
    cout << "AVER_VALUE: " << A1.averVal() << '\n';
    double t2[M][N] = {{46, 5, 132}, {65, 4, 888}};
    Array A2(t2);
    cout << "AVER_VALUE: " << A2.averVal() << '\n';
    double t3[M][N] = {{13, 24, 5}, {4, 13, 2}};
    Array A3(t3);
    cout << "AVER_VALUE: " << A3.averVal() << '\n';
    return 0;
}