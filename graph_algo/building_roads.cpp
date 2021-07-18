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

	stack<int> nodes;
	vector<int> u;

	int n, m; cin >> n >> m;

	vector<vector<int>> adjList(n);
	vector<bool> vis(n, 0);

	for(int i = 0, a, b; i < m; i++)
	{
		cin >> a >> b, --a, --b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	for(int i = 0, h; i < n; i++)
	{
		if(vis[i]) continue;

		vis[i] = 1, nodes.push(i);

		while(!nodes.empty())
		{
			h = nodes.top(); nodes.pop();
			for(auto &nxt : adjList[h])
			{
				if(vis[nxt]) continue;
				vis[nxt] = 1, nodes.push(nxt);
			}
		}

		u.emplace_back(i + 1);
	}

	cout << u.size() - 1 << endl;
	for(int i = 1; i < u.size(); i++)
		cout << u[i-1] << ' ' << u[i] << '\n';

	return 0;
}