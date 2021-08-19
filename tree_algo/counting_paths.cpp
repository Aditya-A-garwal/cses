#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define ff first
#define ss second

#define pb emplace_back

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

const int mxN = 200003;
const int mxLog = 19;

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	const int mxN = 200001, mxLog = 19;

	int n, q; cin >> n >> q;
	vector<vi> adj(n);
	vector<array<int, mxLog>> pre(n, array<int, mxLog>());
	vi D(n, 0), res(n, 0);

	// function to get k-th ancestor of tree using binary lifting
	auto ances = [&](int a, int d) -> int
	{
		for(int i = mxLog - 1; i >= 0; i--)
			if(d & (1 << i))
				a = pre[a][i];
		return a;
	};

	// function to find LCA of two nodes
	auto lca = [&](int a, int b) -> int
	{
		if(D[a] > D[b])
			swap(a, b);

		b = ances(b, D[b] - D[a]);
		if(a == b)
			return a;

		for(int i = mxLog - 1; i >= 0; i--)
			if(pre[a][i] != pre[b][i])
				a = pre[a][i], b = pre[b][i];

		return pre[a][0];
	};

	// function to preprocess ancestor table, claculate depths
	function<void(int, int)> dfs = [&](int cur, int prv)
	{
		pre[cur][0] = prv;
		for(int j = 1; j < mxLog; j++)
			pre[cur][j] = pre[pre[cur][j-1]][j-1];

		for(auto &nxt : adj[cur])
			if(nxt != prv)
				D[nxt] = 1 + D[cur], dfs(nxt, cur);
	};

	// perform dfs and find out the results of every node
	function<int(int, int)> DFS = [&](int cur, int prv) -> int
	{
		for(auto &nxt : adj[cur])
			if(nxt != prv)
				res[cur] += DFS(nxt, cur);
		return res[cur];
	};

	// Create tree
	for(int i = 1, x, y; i < n; i++)
	{
		cin >> x >> y, --x, --y;
		adj[x].pb(y), adj[y].pb(x);
	}

	dfs(0, 0);

	int a, b, c;
	while(q--)
	{
		cin >> a >> b, --a, --b, c = lca(a, b);

		res[a] += 1, res[b] += 1, res[c] -= 1;
		res[pre[c][0]] -= c != 0;
	}

	DFS(0, 0);

	for(auto &e : res)
		cout << e << ' ';
	cout << '\n';

	return 0;
}