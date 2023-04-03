#include <iostream>
using namespace std;
template<class T>
T aver(T x[], int n) {
    T averVal = 0;
    for (int i = 0; i < n; i ++) averVal += x[i];
    averVal /= n;
    return averVal;
}
int main() {
    int arr1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "The Average Value of [int]Arr1 is : " << aver(arr1, 10) << '\n';
    double arr2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "The Average Value of [double]Arr2 is : " << aver(arr2, 10) << '\n';
    return 0;
}