#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int M = 1e4 + 10;
void solve() {
    int n, dp[M];
    dp[1] = 2;
    cin >> n;
    for (int i = 2; i <= n; i ++)
        dp[i] = dp[i - 1] + 4 * (i - 1) + 1;
    cout << dp[n] << '\n';
}
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) solve();
    return 0;
}