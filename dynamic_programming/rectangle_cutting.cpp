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

ll dp[501][501];

ll solve(ll x, ll y)
{
	if(y > x)
		swap(x, y);

	if(dp[x][y] == -1)
	{
		ll res = llinf, xi = x >> 1, yi = y >> 1;

		for(int i = 1; i <= xi; i++)
			res = min(res, 1 + solve(i, y) + solve(x - i, y));

		for(int i = 1; i <= yi; i++)
			res = min(res, 1 + solve(x, i) + solve(x, y - i));

		dp[x][y] = res;
	}
	return dp[x][y];
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll x, y; cin >> x >> y;
	memset(dp, -1, sizeof(dp));

	for(int i = 1; i <= 500; i++)
		dp[i][i] = 0;

	cout << solve(x, y) << '\n';

	return 0;
}
