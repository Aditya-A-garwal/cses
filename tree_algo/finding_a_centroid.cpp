#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vi = vector<int>;
using vll = vector<ll>;

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

	int n; cin >> n;
	vector<vi> adj(n);
	vi sz(n);
	vi depth(n);

	function<int(int, int)> dfs1 = [&](int cur, int prv) {

		for(auto &nxt : adj[cur]) {
			if(nxt != prv) {
				depth[nxt] = 1 + depth[cur];
				sz[cur] += dfs1(nxt, cur);
			}
		}

		return ++sz[cur];
	};

	for(int i = 1, u, v; i < n; i++) {
		cin >> u >> v, --u, --v;

		adj[u].emplace_back(v),
		adj[v].emplace_back(u);
	}

	depth[0] = 0;
	dfs1(0, 0);

	for(int cur = 0; cur < n; cur++) {
		// check if current node can be centroid
		bool flag = 1;
		int subsz;

		for(auto &nxt : adj[cur]) {

			if(depth[nxt] > depth[cur])
				subsz = sz[nxt];
			else
				subsz = sz[0] - sz[cur];

			if(subsz*2 > n) {
				flag = 0;
				break;
			}
		}

		if(flag) {
			cout << ++cur << '\n';
			return 0;
		}
	}

	cout << -1 << '\n';

	return 0;
}