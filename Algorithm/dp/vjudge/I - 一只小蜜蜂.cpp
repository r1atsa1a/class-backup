#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long LL;
const int M = 55;
int main() {
    IOS
    int t;
    LL dp[M];
    dp[1] = 1, dp[2] = 1;
    for (int i = 3; i <= 49; i ++)
        dp[i] = dp[i - 1] + dp[i - 2];
    cin >> t;
    while (t --) {
        int l, r;
        cin >> l >> r;
        cout << dp[r - l + 1] << '\n';
    }   
    return 0;
}
