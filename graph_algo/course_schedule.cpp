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

	int n, m, x, y; cin >> n >> m;
	vector<vector<int>> adjlst(n);
	vector<int> in(n, 0), vis(n, 0), ans; ans.reserve(n);

	function<void(int)> DFS = [&](int cur)
	{
		vis[cur] = 1;

		for(auto &nxt : adjlst[cur])
		{
			if(!vis[nxt])
				DFS(nxt);
			else if(vis[nxt] == 1)
			{
				cout << "IMPOSSIBLE\n";
				exit(0);
			}
		}

		ans.emplace_back(cur);
		vis[cur] = 2;
	};

	while(m--)
		cin >> x >> y, adjlst[--x].emplace_back(--y), in[y]++;

	for(int i = 0; i < n; i++)
		if(!in[i])
			DFS(i);

	if(ans.size() != n)
	{
		cout << "IMPOSSIBLE\n";
		return 0;
	}

	for(auto it = ans.rbegin(); it != ans.rend(); it++)
		cout << 1 + *it << ' ';
	cout << '\n';

	return 0;
}
