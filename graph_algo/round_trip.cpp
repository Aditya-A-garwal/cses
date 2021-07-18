#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	vector<int> ans;

	int n, m; cin >> n >> m;

	vector<int> vis(n, 0);
	vector<vector<int>> adjList(n);

	function<bool(int, int)> DFS = [&](int cur, int prv) -> bool
	{
		for(int nxt : adjList[cur])
		{
			if(!vis[nxt])
			{
				vis[nxt] = 1;
				if(DFS(nxt, cur))
				{
					ans.emplace_back(cur);
					if(cur == ans[0]) // this is the node which was found
					{
						cout << ans.size() << '\n';
						for(auto &e : ans)
							cout << e+1 << ' ';
						exit(0);
					}
					return 1;
				}
			}
			else
			{
				if(nxt != prv)
				{
					ans.emplace_back(nxt);
					ans.emplace_back(cur);
					return 1;
				}
			}
		}

		return 0;
	};

	for(int i = 0, a, b; i < m; i++)
	{
		cin >> a >> b, --a, --b;
		adjList[a].emplace_back(b), adjList[b].emplace_back(a);
	}

	for(int i = 0; i < n; i++)
		if(!vis[i])
			vis[i] = 1, DFS(i, -1);

	cout << "IMPOSSIBLE\n";

	return 0;
}