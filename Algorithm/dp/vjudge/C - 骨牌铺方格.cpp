#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long LL;
const int M = 55;
int main() {
    IOS
    int n;
    LL dp[M];
    dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= 50; i ++)
        dp[i] = dp[i - 1] + dp[i - 2];
    while (cin >> n) cout << dp[n] << '\n';
    return 0;
}