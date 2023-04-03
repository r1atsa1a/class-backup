#include <stdio.h>
#include <stdlib.h>
int arr[10];
void solve() {
    //skip the random part
    // for (int i = 0; i < 10; i ++) {
    //     srand(i);
    //     arr[i] = rand();
    // }
    FILE *fp = fopen("data.dat", "wb");
    for (int i = 0; i < 10; i ++) fprintf(fp, "%d ", arr[i]);
    fclose(fp);
}
double calculate() {
    int sum = 0;
    FILE *fp = fopen("data.dat", "rb");
    for (int i = 0; i < 10; i ++) {
        int x;
        fscanf(fp, "%d", &x);
        sum += x;
    }
    fclose(fp);
    return sum * 1.0 / 10;
}
int main() {
    // 1 2 3 4 5 6 7 8 9 10
    for (int i = 0; i < 10; i ++) arr[i] = i + 1;
    solve();
    printf("%.2lf\n", calculate());
    // 5 6 7 8 9 10 11 12 13 14
    for (int i = 0; i < 10; i ++) arr[i] = i + 5;
    solve();
    printf("%.2lf\n", calculate());
    // 8 9 10 11 12 13 14 15 16 17
    for (int i = 0; i < 10; i ++) arr[i] = i + 8;
    solve();
    printf("%.2lf\n", calculate());
    return 0;
}