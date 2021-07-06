#include<bits/stdc++.h>

#define mod 1000000007

using namespace std;

int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	int dp_[n + 8], *dp = dp_ + 6;
	memset(dp_, 0, sizeof(dp_));

	dp[0] = dp[1] = 1;
	for(int i = 2; i <= n; i++)
		for(int j = i-6; j <= i-1; j++)
			dp[i] = (dp[i] + dp[j]) % mod;

	cout << dp[n] << '\n';

	return 0;
}