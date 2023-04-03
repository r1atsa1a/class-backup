#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int M = 35;
void solve() {
    int n, dp[M];
    cin >> n;
    dp[1] = 1, dp[2] = 3;
    for (int i = 3; i <= n; i ++)
        dp[i] = dp[i - 1] + 2 * dp[i - 2];
    cout << dp[n] << '\n';
}
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) solve();
    return 0;
}