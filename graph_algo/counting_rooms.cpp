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

	vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
	stack<pair<int, int>> coors;

	int n, m, ans{0}; char c; cin >> n >> m;

	bool ar[n + 2][m + 2];

	memset(ar, 1, sizeof(ar));

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> c, ar[i][j] = c == '#';

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(ar[i][j]) continue;
			ans++;

			ar[i][j] = 1;
			coors.push({i, j});

			while(!coors.empty())
			{
				auto [y, x] = coors.top(); coors.pop();

				for(auto &[b, a] : dirs)
				{
					if(ar[y + b][x + a]) continue;

					ar[y + b][x + a] = 1;
					coors.push({y + b, x + a});
				}
			}
		}
	}


	cout << ans << '\n';

	return 0;
}