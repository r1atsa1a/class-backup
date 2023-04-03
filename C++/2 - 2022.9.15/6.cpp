#include <iostream>
using namespace std;
int solve(int x) {
    int t = x, ans = 0, k;
    while (t) {
        k = t % 10;
        t /= 10;
        ans += k * k * k;
    }
    if (ans == x) return 1;
    else return 0;
}
int main() {
    int n;
    n = 153;
    if (solve(n)) printf("%d YES\n", n);
    else printf("%d NO\n", n);
    n = 256;
    if (solve(n)) printf("%d YES\n", n);
    else printf("%d NO\n", n);
    n = 407;
    if (solve(n)) printf("%d YES\n", n);
    else printf("%d NO\n", n);
    return 0;
}