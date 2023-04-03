#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int M = 35;
void solve() {
    int n, dp[M];
    dp[0] = 3;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        dp[i] = 2 * (dp[i - 1] - 1);
    cout << dp[n] << '\n';
}
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) solve();
    return 0;
}