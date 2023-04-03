#include <iostream>
#include <algorithm>
using namespace std;
void swaparr(int arr1[], int arr2[], int len) {
    for (int i = 0; i < len; i ++) swap(arr1[i], arr2[i]);
}
int main() {
    int n1 = 10;
    int arr1_1[10] = {4, 9, 86, 5, 13, 29, 8, 4, 65, 1};
    int arr1_2[10] = {16, 54, 5, 649, 84, 55, 1, 53, 13, 15};
    printf("arr1: "); for (int i = 0; i < n1; i ++) cout << arr1_1[i] << " ";
    printf("\narr2: "); for (int i = 0; i < n1; i ++) cout << arr1_2[i] << " "; puts("");
    swaparr(arr1_1, arr1_2, n1);
    printf("arr1: "); for (int i = 0; i < n1; i ++) cout << arr1_1[i] << " ";
    printf("\narr2: "); for (int i = 0; i < n1; i ++) cout << arr1_2[i] << " "; puts("\n");
    int n2 = 10;
    int arr2_1[10] = {78, 45, 61, 32, 79, 8, 4, 65, 13, 2};
    int arr2_2[10] = {1, 2, 36, 5, 1, 23, 54, 61, 32, 56};
    printf("arr1: "); for (int i = 0; i < n2; i ++) cout << arr2_1[i] << " ";
    printf("\narr2: "); for (int i = 0; i < n2; i ++) cout << arr2_2[i] << " "; puts("\n");
    swaparr(arr2_1, arr2_2, n2);
    printf("arr1: "); for (int i = 0; i < n2; i ++) cout << arr2_1[i] << " ";
    printf("\narr2: "); for (int i = 0; i < n2; i ++) cout << arr2_2[i] << " "; puts("\n");
    int n3 = 10;
    int arr3_1[10] = {9, 7, 46, 5, 113, 26, 58, 4, 65, 1};
    int arr3_2[10] = {13, 24, 98, 7, 987, 4, 65, 3, 2, 1};
    printf("arr1: "); for (int i = 0; i < n3; i ++) cout << arr3_1[i] << " ";
    printf("\narr2: "); for (int i = 0; i < n3; i ++) cout << arr3_2[i] << " "; puts("");
    swaparr(arr3_1, arr3_2, n3);
    printf("arr1: "); for (int i = 0; i < n3; i ++) cout << arr3_1[i] << " ";
    printf("\narr2: "); for (int i = 0; i < n3; i ++) cout << arr3_2[i] << " "; puts("");
    return 0;
}