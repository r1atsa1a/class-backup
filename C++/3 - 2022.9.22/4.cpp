#include <iostream>
using namespace std;
int quick_pow(int a, int k) {
    int res = 1;
    while (k) {
        if (k & 1) res = (long long) res * a;
        k >>= 1;
        a = (long long) a * a;
    }
    return res;
}
int main() {
    int x1 = 5, y1 = 4;
    printf("%d^%d = %d\n", x1, y1, quick_pow(x1, y1));
    int x2 = 15, y2 = 3;
    printf("%d^%d = %d\n", x2, y2, quick_pow(x2, y2));
    int x3 = 32, y3 = 5;
    printf("%d^%d = %d\n", x3, y3, quick_pow(x3, y3));
    return 0;
}