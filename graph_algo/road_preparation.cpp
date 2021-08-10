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

	int n, m; cin >> n >> m;
	ll res = 0;

	// not enough edges, directly exit
	if(m < n-1)
	{
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	
	vector<tuple<ll, int, int>> edges(m);
	vector<int> dsu(n);

	function<int(int)> getSet = [&](int node)
	{
		while(dsu[node] != node)
			node = dsu[node];

		return node;
	};

	function<void(int, int)> makeSame = [&](int node1, int node2)
	{
		node1 = getSet(node1), node2 = getSet(node2);

		if(node1 > node2)
			swap(node1, node2);

		dsu[node2] = node1;
	};

	// set all nodes to belong to their own sets
	for(int i = 0; i < n; i++)
		dsu[i] = i;

	for(auto &[c, b, a] : edges)
	{
		cin >> a >> b >> c, --a, --b;
		if(a > b)
			swap(a, b);
	}

	sort(edges.begin(), edges.end());
	for(auto &[c, b, a] : edges)
		if(getSet(a) != getSet(b))
			res += c, makeSame(a, b);

	// if all nodes do not belong to the same component, not possible to get min spanning tree
	for(int i = 0, j = getSet(0); i < n; i++)
	{
		if(getSet(i) != j)
		{
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}

	cout << res << '\n';

	return 0;
}