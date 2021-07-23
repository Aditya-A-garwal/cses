#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int inf = 1e9 + 10;
const ll llinf = 1e18 + 10;

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, tot = 0; cin >> n;
	vector<int> ar(n + 1), ans;

	for(int i = 1; i <= n; i++)
		cin >> ar[i], tot += ar[i];

	vector<vector<bool>> dp(n + 2, vector<bool>(tot + 1, 0));
	// dp[i][j] is true if it is possible to get sum = j using ANY subset of the first i coins
	// else false

	for(int i = 0; i <= n; i++)
		dp[i][0] = 1;

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= tot; j++)
		{
			// If the current element is not included, it should be possible to get sum = j using only the
			// previous elements
			// else if the current element is used, it should be possible to get sum = j - ar[i] using only the
			// previous elements and j - ar[i] should not be negative
			// if either one is possible, it is possible to get sum = j using the first i coins
			dp[i][j] = dp[i - 1][j] or (j - ar[i] >= 0 and dp[i - 1][j - ar[i]]);
		}
	}

	for(int i = 1; i <= tot; i++)
		if(dp[n][i])
			ans.emplace_back(i);

	cout << ans.size() << '\n';
	for(auto &e : ans)
		cout << e << ' ';

	cout << '\n';

	return 0;
}