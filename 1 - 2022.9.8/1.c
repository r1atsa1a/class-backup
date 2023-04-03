#include <stdio.h>
int square(int u) {
    return u * u;
}
int main() {
    printf("%d^2 = %d\n", 2, square(2));
    printf("%d^2 = %d\n", 3, square(3));
    printf("%d^2 = %d\n", 4, square(4));
    return 0;
}