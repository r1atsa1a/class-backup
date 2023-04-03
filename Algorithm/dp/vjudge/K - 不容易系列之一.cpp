#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long LL;
const int M = 55;
int main() {
    IOS
    LL dp[M];
    dp[2] = 1, dp[3] = 2;
    for (int i = 4; i <= 20; i ++)
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
    int n;
    while (cin >> n) cout << dp[n] << '\n';
    return 0;
}
