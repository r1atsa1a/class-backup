#include <iostream>
#include <cstring>
using namespace std;
const int M = 110, N = 110, INF = 0x3f3f3f3f;
class Array {
    public:
        Array(double (*_arr)[4], int _lenM, int _lenN) {
            double sum = 0; memset(A, 0, sizeof A);
            lenM = _lenM, lenN = _lenN;
            maxVal = -INF, minVal = INF;
            for (int i = 0; i < _lenM; i ++) {
                for (int j = 0; j < _lenN; j ++) {
                    A[i][j] = _arr[i][j];
                    sum += A[i][j];
                    if (A[i][j] > maxVal) maxVal = A[i][j];
                    if (A[i][j] < minVal) minVal = A[i][j];
                }
            }
            aver = 1.0 * sum / (_lenM * _lenN);
        }
        void Disp() {
            cout << aver << " " << maxVal << " " << minVal << '\n';
        }
    private:
        int lenM, lenN;
        double A[M][N], maxVal, minVal, aver;
};
int main() {
    cout << "Average | Max | Min" << '\n';
    double T1[2][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}};
    Array arr1(T1, 2, 4);
    arr1.Disp();
    double T2[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    Array arr2(T2, 3, 4);
    arr2.Disp();
    double T3[1][4] = {{1, 2, 3, 4}};
    Array arr3(T3, 1, 4);
    arr3.Disp();
    return 0;
}