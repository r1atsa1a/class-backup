#include <iostream>
using namespace std;
const int M = 110, INF = 0x3f3f3f3f;
class Array {
    public:
        Array(int *_arr, int _len) {
            len = _len;
            Amax = -INF, Amin = INF;
            int sum = 0;
            for (int i = 0; i < _len; i ++) {
                A[i] = _arr[i];
                if (A[i] > Amax) {Amax = A[i]; maxPos = i;}
                if (A[i] < Amin) {Amin = A[i]; minPos = i;}
                sum += A[i];
            }
            aver = 1.0 * sum / len;
        }
        double averVal() {
            return aver;
        }
        double maxVal() {
            return Amax;
        }
        double maxValPos() {
            return maxPos;
        }
        double minVal() {
            return Amin;
        }
        double minValPos() {
            return minPos;
        }
    private:
        int len;
        double A[M], aver;
        double Amax, maxPos;
        double Amin, minPos;
};
int main() {
    cout << "Average | Max | MaxPos | Min | MinPos" << '\n';
    int T1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Array arr1(T1, 10);
    cout << arr1.averVal() << " ";
    cout << arr1.maxVal() << " " << arr1.maxValPos() << " ";
    cout << arr1.minVal() << " " << arr1.minValPos() << '\n';
    int T2[8] = {7, 89, 45, 6, 1, 23, 4, 5};
    Array arr2(T2, 8);
    cout << arr2.averVal() << " ";
    cout << arr2.maxVal() << " " << arr2.maxValPos() << " ";
    cout << arr2.minVal() << " " << arr2.minValPos() << '\n';
    int T3[12] = {1, 23, 56, 4, 4, 189, 5, 12, 3, 16, 5, 7};
    Array arr3(T3, 12);
    cout << arr3.averVal() << " ";
    cout << arr3.maxVal() << " " << arr3.maxValPos() << " ";
    cout << arr3.minVal() << " " << arr3.minValPos() << '\n';
    return 0;
}