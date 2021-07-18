#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int inf = 1e9 + 1;

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	vector<int> ans;
	queue<int> nodes;

	int n, m; cin >> n >> m;

	vector<vector<int>> adjList(n);
	vector<array<int, 2>> u(n, {inf, -1});

	for(int i = 0, a, b; i < m; i++)
	{
		cin >> a >> b, --a, --b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	u[0][0] = 0, nodes.emplace(0);

	while(!nodes.empty())
	{
		int h = nodes.front(); nodes.pop();

		for(auto &nxt : adjList[h])
		{
			if((1 + u[h][0]) < u[nxt][0])
				u[nxt][0] = 1 + u[h][0], u[nxt][1] = h, nodes.emplace(nxt);
		}

		if(h == n-1)
			break;
	}

	if(u[n-1][0] >= inf)
		cout << "IMPOSSIBLE";
	else
	{
		cout << 1 + u[n-1][0] << '\n';
		ans.reserve(u[n-1][0] + 1);

		int x = n-1;
		ans.emplace_back(x + 1);

		while(1)
		{
			x = u[x][1];
			ans.emplace_back(x + 1);
			if(x == 0)
				break;
		}

		for(auto it = ans.rbegin(); it != ans.rend(); it++) cout << *it << ' ';
	}

	cout << '\n';

	return 0;
}