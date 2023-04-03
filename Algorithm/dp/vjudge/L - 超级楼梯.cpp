#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int M = 45;
void solve() {
    int n, dp[M];
    dp[1] = 1, dp[2] = 2;
    cin >> n; -- n;
    for (int i = 3; i <= n; i ++)
        dp[i] = dp[i - 1] + dp[i - 2];
    cout << dp[n] << '\n';
}
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) solve();
    return 0;
}