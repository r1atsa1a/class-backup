#include <iostream>
using namespace std;
const int INF = 0x3f3f3f3f;
class Array {
    public:
        Array(int *_arr, int n) {
            size = n;
            ptr = new int[size];
            for (int i = 0; i < n; i ++)
                *(ptr + i) = _arr[i];
        }
        ~Array() {
            delete ptr;
        }
        int maxVal() {
            int t = -INF;
            for (int i = 0; i < size; i ++)
                if (*(ptr + i) > t) t = *(ptr + i);
            return t;
        }
    private:
        int *ptr, size;
};
int main() {
    int n1 = 10, t1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Array A1(t1, n1);
    cout << "MAX_VALUE: " << A1.maxVal() << '\n';
    int n2 = 5, t2[5] = {46, 5, 132, 65, 4};
    Array A2(t2, n2);
    cout << "MAX_VALUE: " << A2.maxVal() << '\n';
    int n3 = 15, t3[15] = {13, 24, 5, 99, 865, 4, 13, 2, 6, 5, 4, 12, 798, 1, 99};
    Array A3(t3, n3);
    cout << "MAX_VALUE: " << A3.maxVal() << '\n';
    return 0;
}