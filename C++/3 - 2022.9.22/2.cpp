#include <iostream>
#include <cmath>
using namespace std;
const int LEN = 8;
void bintodec(char *str, int &num) {
    int k = 0;
    for (int i = LEN - 1; i >= 0; i --) {
        num += (str[i] - '0') * pow(2, k);
        k ++;
    }
}
int main() {
    int n1 = 0;
    char bin1[10] = "11111111";
    bintodec(bin1, n1);
    printf("%s(B) -> %d(H)\n", bin1, n1);
    int n2 = 0;
    char bin2[10] = "11001011";
    bintodec(bin2, n2);
    printf("%s(B) -> %d(H)\n", bin2, n2);
    int n3 = 0;
    char bin3[10] = "11000111";
    bintodec(bin3, n3);
    printf("%s(B) -> %d(H)\n", bin3, n3);
    return 0;
}