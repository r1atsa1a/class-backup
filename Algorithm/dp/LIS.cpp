#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int M = 1010;
int main() {
	IOS
	int n, ans = 0;
	int arr[M], dp[M];
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> arr[i];
	for (int i = 1; i <= n; i ++) {
		for (int j = i - 1; j >= 0; j --)
			if (arr[j] < arr[i]) dp[i] = max(dp[i], dp[j] + 1);
		ans = max(ans, dp[i]);
	}
	cout << ans << '\n';
	for (int i = 1; i <= n; i ++) cout << dp[i] << " "; cout << '\n';
	cout << ans << '\n';
	return 0;
}