#include <iostream>
using namespace std;
void solve() {
    for (int i = 100; i <= 300; i ++)
        if (!(i % 3) && !(i % 5)) cout << i << " ";
}
int main() {
    solve();
    return 0;
}