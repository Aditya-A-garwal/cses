#include<bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	// FAST GREEDY SOLUTION
	// int n, ans = 0; cin >> n;

	// while(n)
	// {
	// 	int digi = -1, buff = n;
	// 	while(buff)
	// 	{
	// 		digi = max(digi, buff % 10);
	// 		buff /= 10;
	// 	}
	// 	n -= digi, ans++;
	// }

	// cout << ans << '\n';

	// DP SOLUTION
	const int INF = 1e7;
	int n; cin >> n;
	vector<int> dp(n + 1);
	dp[0] = 0;

	for(int i = 1, buff; i <= n; i++)
	{
		buff = i, dp[i] = INF;
		while(buff)
		{
			dp[i] = min(dp[i], dp[i - (buff % 10)]);
			buff /= 10;
		}
		++dp[i];
	}

	cout << dp[n] << '\n';

	return 0;
}