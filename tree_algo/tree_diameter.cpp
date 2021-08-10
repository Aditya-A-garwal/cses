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

	int n; cin >> n;
	vector<vector<int>> adjlst(n);
	vector<int> dist(n); dist[0] = 0;

	for(int i = 1, a, b; i < n; i++)
	{
		cin >> a >> b, --a, --b;
		adjlst[a].emplace_back(b), adjlst[b].emplace_back(a);
	}

	if(n <= 3)
	{
		cout << --n << '\n';
		return 0;
	}

	function<void(int, int)> dfs = [&](int cur, int prv)
	{
		for(auto &nxt : adjlst[cur])
		{
			if(nxt == prv)
				continue;
			dist[nxt] = 1 + dist[cur];
			dfs(nxt, cur);
		}
	};

	dfs(0, -1);
	int farthestNode = max_element(dist.begin(), dist.end()) - dist.begin();

	dist[farthestNode] = 0;
	dfs(farthestNode, -1);

	cout << *max_element(dist.begin(), dist.end()) << '\n';

	return 0;
}