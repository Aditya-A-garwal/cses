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

const ll mod = 1e9 + 7;

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n, m, x, y; cin >> n >> m;
	vector<vector<int>> parents(n);
	vector<ll> ways(n, -1); ways[0] = 1;

	while(m--)
		cin >> x >> y, parents[--y].emplace_back(--x);

	function<ll(int)> findways = [&](int cur)
	{
		if(ways[cur] == -1)
		{
			ways[cur] = 0;
			for(auto &prv : parents[cur])
				(ways[cur] += findways(prv)) %= mod;
		}

		return ways[cur];
	};

	cout << findways(n - 1) << '\n';

	return 0;
}