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

	int n, m; cin >> n >> m;
	vector<vector<int>> adjList(n);
	vector<int> color(n, -1);

	for(int i = 0, a, b; i < m; i++)
	{
		cin >> a >> b, --a, --b;
		adjList[a].emplace_back(b), adjList[b].emplace_back(a);
	}

	for(int i = 0; i < n; i++)
	{
		if(color[i] != -1) continue;

		color[i] = 0, nodes.emplace(i);

		while(!nodes.empty())
		{
			int h = nodes.top(); nodes.pop();

			for(auto &nxt : adjList[h])
			{
				if(color[nxt] == -1)
				{
					color[nxt] = 1 - color[h], nodes.emplace(nxt);
				}
				else if(color[nxt] == color[h])
				{
					cout << "IMPOSSIBLE\n";
					return 0;
				}
			}
		}
	}

	for(auto &e : color)
		cout << 1 + e << ' ';

	cout << '\n';

	return 0;
}