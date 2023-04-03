#include <iostream>
#include <cmath>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int INF = 0x3f3f3f3f;
double F(double x) {
    return 0.7 * x + 8 * sin(6 * x) + 9 * cos(3 * x);
}
int main() {
    IOS
    double maxFx = -INF;
    for (double i = 0; i <= 10; i += 0.005)
        maxFx = max(maxFx, F(i));
    cout << maxFx << '\n';
    return 0;
}
