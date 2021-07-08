#include<bits/stdc++.h>

#define mod 1000000007

using namespace std;

int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, x, ans = 0; cin >> n >> x;
	vector<int> ar(n + 1);
	vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

	for(int i = 1; i <= n; i++) cin >> ar[i];

	if(ar[1])
		dp[1][ar[1]] = 1;
	else
		for(int j = 1; j <= x; j++)
			dp[1][j] = 1;

	for(int i = 2; i <= n; i++)
	{
		if(ar[i])
		{
			dp[i][ar[i]] = dp[i-1][ar[i]];
			if(ar[i] > 1) dp[i][ar[i]] = (dp[i][ar[i]] + dp[i-1][ar[i]-1]) % mod;
			if(ar[i] < x) dp[i][ar[i]] = (dp[i][ar[i]] + dp[i-1][ar[i]+1]) % mod;
		}
		else
		{
			dp[i][1] = (dp[i-1][1] + dp[i-1][2]) % mod;
			dp[i][x] = (dp[i-1][x] + dp[i-1][x-1]) % mod;
			for(int j = 2; j < x; j++)
				dp[i][j] = (((dp[i-1][j-1] + dp[i-1][j+1]) % mod) + dp[i-1][j]) % mod;
		}
	}

	for(int j = 1; j <= x; j++)
		ans = (ans + dp[n][j]) % mod;

	cout << ans << '\n';

	return 0;
}