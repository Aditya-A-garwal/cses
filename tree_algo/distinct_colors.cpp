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

vi res, c;
vector<vi> adj;
vector<set<int>> sz;

void dfs(int cur, int prv) {

	int biggest = cur;

	for(auto &nxt : adj[cur]) {
		if(nxt == prv)
			continue;
		dfs(nxt, cur);
		if(sz[nxt].size() > sz[biggest].size())
			biggest = nxt;
	}

	swap(sz[cur], sz[biggest]);

	for(auto &nxt : adj[cur]) {
		if(nxt == prv or nxt == biggest)
			continue;
		sz[cur].insert(sz[nxt].begin(), sz[nxt].end());
		sz[nxt].clear();
	}

	sz[cur].insert(c[cur]);
	res[cur] = sz[cur].size();
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	c.resize(n), res.resize(n);
	adj.resize(n);
	sz.resize(n);

	for(int i = 0; i < n; i++)
		cin >> c[i];

	for(int i = 1, u, v; i < n; i++) {
		cin >> u >> v, --u, --v;
		adj[u].emplace_back(v),
		adj[v].emplace_back(u);
	}

	dfs(0, 0);

	for(int i = 0; i < n; i++) {
		cout << res[i] << ' ';
	}
	cout << '\n';

	return 0;
}
