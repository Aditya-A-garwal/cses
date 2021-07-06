#include<bits/stdc++.h>

#define mod 1000000007

using namespace std;

int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, x; cin >> n >> x;
	vector<int> ar(n), dp(x + 1, 0);

	for(auto &e : ar) cin >> e;

	sort(ar.begin(), ar.end());

	dp[0] = 1;
	for(int j = 0; j < n; j++)
	{
		for(int i = 1; i <= x; i++)
		{
			if(i - ar[j] < 0) continue;
			dp[i] = (dp[i] + dp[i - ar[j]]) % mod;
		}
	}

	cout << dp[x] << '\n';

	return 0;
}