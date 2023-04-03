#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long LL;
const int M = 25;
int main() {
    IOS
    LL dp[M], fac[M];
    dp[2] = 1, dp[3] = 2; fac[0] = 1;
    for (int i = 4; i <= 20; i ++)
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
    for (int i = 1; i <= 20; i ++)
        fac[i] = fac[i - 1] * i;
    int t;
    cin >> t;
    while (t --) {
        int n, m;
        cin >> n >> m;
        LL ans = fac[n] / (fac[m] * fac[n - m]) * dp[m];
        cout << ans << '\n';
    }
    return 0;
}