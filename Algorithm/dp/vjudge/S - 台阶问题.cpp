#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int M = 1e5 + 10, MOD = 100003;
int main() {
    IOS
    int n, k, dp[M] = {0};
    cin >> n >> k;
    int sum = 0;
    for (int i = 1; i <= k; i ++) {
        dp[i] = (sum + 1) % MOD;
        sum += dp[i];
    }
    // for (int i = 1; i <= n; i ++) cout << dp[i] << " ";
    // cout << '\n';
    for (int i = k + 1; i <= n; i ++) {
        for (int j = i - 1; j >= i - k; j --) {
            dp[i] += dp[j];
            dp[i] %= MOD;
        }
    }
    // for (int i = 1; i <= n; i ++) cout << dp[i] << " ";
    // cout << '\n';
    cout << dp[n] << '\n';
    return 0;
}