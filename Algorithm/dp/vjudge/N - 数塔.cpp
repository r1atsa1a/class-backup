#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int M = 110;
void solve() {
    int n;
    int w[M][M], dp[M][M];
    cin >> n;
    memset(w, 0, sizeof w);
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= i; j ++)
            cin >> w[i][j];
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= i; j ++)
            if (j > 1) dp[i][j] = w[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
            else dp[i][j] = w[i][j] + dp[i - 1][j];
    int ans = 0;
    for (int i = 1; i <= n; i ++)
        ans = max(ans, dp[n][i]);
    cout << ans << '\n';
}
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) solve();
    return 0;
}