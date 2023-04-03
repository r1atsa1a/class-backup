#include <stdio.h>
int n, arr[1010];
void sort() {
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n - i - 1; j ++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}
int main() {
    // 1 3 2
    n = 3; arr[0] = 1; arr[1] = 3; arr[2] = 2;
    sort();
    for (int i = 0; i < n; i ++) printf("%d ", arr[i]); puts("");
    // 5 4 9
    n = 3; arr[0] = 5; arr[1] = 4; arr[2] = 9;
    sort();
    for (int i = 0; i < n; i ++) printf("%d ", arr[i]); puts("");
    // 9 8 7 4 2
    n = 5; arr[0] = 9; arr[1] = 8; arr[2] = 7; arr[3] = 4; arr[4] = 2;
    sort();
    for (int i = 0; i < n; i ++) printf("%d ", arr[i]); puts("");
    return 0;
}