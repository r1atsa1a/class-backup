#include <iostream>
using namespace std;
const int M = 10;
double aver(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i ++) sum += arr[i];
    return (double)sum / (double)n;
}
int main() {
    int n = 10;
    int arr1[M] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("the average of arr1 is %.2lf\n", aver(arr1, n));
    int arr2[M] = {0, 15, 52, 23, 114, 5545, 116, 17, 68, 989};
    printf("the average of arr2 is %.2lf\n", aver(arr2, n));
    int arr3[M] = {50, 211, 52, 37, 45, 415, 1116, 657, 748, 149};
    printf("the average of arr3 is %.2lf\n", aver(arr3, n));
    return 0;
}