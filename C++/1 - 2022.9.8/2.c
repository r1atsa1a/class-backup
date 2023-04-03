#include <stdio.h>
void swap(int *x, int *y) {
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}
int main() {
    int x, y;
    x = 1, y = 2;
    printf("x = %d, y = %d -> ", x, y);
    swap(&x, &y);
    printf("x = %d, y = %d\n", x, y);
    x = 10, y = 20;
    printf("x = %d, y = %d -> ", x, y);
    swap(&x, &y);
    printf("x = %d, y = %d\n", x, y);
    x = 40, y = 20;
    printf("x = %d, y = %d -> ", x, y);
    swap(&x, &y);
    printf("x = %d, y = %d\n", x, y);
    return 0;
}