#include <iostream>
using namespace std;
const int N = 1e8;
void solve() {
    int sign = 1;
    double PAI = 0;
    for (int i = 1; i <= N; i += 2) {
        PAI += (double)sign * 1.0 / i;
        sign = -sign;
    }
    printf("%.7lf", 4.0 * PAI);
}
int main() {
    solve();
    return 0;
}