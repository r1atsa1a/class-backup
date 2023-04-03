#include <iostream>
using namespace std;
const int M = 2, N = 3;
class Array {
    public:
        Array(double (*_arr)[N]) {
            for (int i = 0; i < N; i ++)
                ptr[i] = new double[M];
            for (int i = 0; i < M; i ++)
                for (int j = 0; j < N; j ++)
                    *(*(ptr + i) + j) = _arr[i][j];
        }
        ~Array() {
            for (int i = 0; i < N; i ++)
                delete [] ptr[i];
        }
        double varVal() {
            double t = 0;
            for (int i = 0; i < M; i ++)
                for (int j = 0; j < N; j ++)
                    t += *(*(ptr + i) + j);
            aver = t / (M * N);
            double ans = 0;
            for (int i = 0; i < M; i ++)
                for (int j = 0; j < N; j ++)
                    ans += (*(*(ptr + i) + j) - aver) * (*(*(ptr + i) + j) - aver);
            return ans / (M * N);
        }
    private:
        double *ptr[N], aver;
};
int main() {
    double t1[M][N] = {{0, 1, 2}, {3, 4, 5}};
    Array A1(t1);
    cout << "D(X) = " << A1.varVal() << '\n';
    double t2[M][N] = {{46, 5, 132}, {65, 4, 888}};
    Array A2(t2);
    cout << "D(X) = " << A2.varVal() << '\n';
    double t3[M][N] = {{13, 24, 5}, {4, 13, 2}};
    Array A3(t3);
    cout << "D(X) = " << A3.varVal() << '\n';
    return 0;
}