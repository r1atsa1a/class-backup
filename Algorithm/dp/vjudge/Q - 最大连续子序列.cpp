#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int M = 1e4 + 10;
int main() {
	IOS
	for (;;) {
		int n, ans = -1;
		int arr[M], dp[M];
		pair<int, int> res;
		cin >> n;
		if (!n) break;
		for (int i = 1; i <= n; i ++) cin >> arr[i];
		int l = 1, r = 1;
		for (int i = 1; i <= n; i ++) {
			// dp[i] = max(dp[i - 1] + arr[i], arr[i]);
			if (dp[i - 1] > 0) {
				dp[i] = dp[i - 1] + arr[i];
				r = i;
			} else {
				dp[i] = arr[i];
				l = i, r = i;
			}
			// ans = max(ans, dp[i]);
			if (dp[i] > ans) {
				ans = dp[i];
				res = {l, r};
			}
		}
		// for (int i = 1; i <= n; i ++) cout << dp[i] << " ";
		if (ans != -1) cout << ans << " ";
        else cout << 0 << " ";
        // cout << res.first << " " << res.second << '\n';
        if (res.first && res.second)
            cout << arr[res.first] << " " << arr[res.second] << '\n';
        else cout << arr[1] << " " << arr[n] << '\n';
		
	}
	return 0;
}