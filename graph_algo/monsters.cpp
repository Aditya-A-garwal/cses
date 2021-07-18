#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define ff first
#define ss second

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using pii = pair<int, int>;

const int inf = 1e8 + 10;

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	array<int, 2> dirs[]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	char dirLabels[] = "UDLR";

	queue<pii> coors;
	pii start;

	vector<char> ans;

	char c; int n, m; cin >> n >> m;

	vector<vector<int>> ar(n + 2, vector<int>(m + 2, -1));
	vector<vector<char>> dir(n + 2, vector<char>(m + 2));

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin >> c;
			if(c != '#')
			{
				ar[i][j] = 0;
				if(c == 'A') start = {i, j};
				else if(c == 'M') coors.emplace(i, j);
				else ar[i][j] = inf;
			}
		}
	}

	while(!coors.empty())
	{
		auto [y, x] = coors.front(); coors.pop();
		ar[y][x]++;
		for(int cntr = 0; cntr < 4; cntr++)
		{
			auto &[yy, xx] = dirs[cntr];
			if(ar[y][x] < ar[y + yy][x + xx])
				ar[y + yy][x + xx] = ar[y][x], coors.emplace(y + yy, x + xx);
		}
		ar[y][x]--;
	}

	coors.push(start);
	while(!coors.empty())
	{
		auto [y, x] = coors.front(); coors.pop();
		ar[y][x]++;
		for(int cntr = 0; cntr < 4; cntr++)
		{
			auto &[yy, xx] = dirs[cntr];
			if(ar[y][x] < ar[y + yy][x + xx])
			{
				ar[y + yy][x + xx] = ar[y][x], coors.emplace(y + yy, x + xx);
				dir[y + yy][x + xx] = dirLabels[cntr];
			}
		}
		ar[y][x]--;

		if(y == 1 or x == 1 or y == n or x == m)
		{
			int i = y, j = x, cntr = ar[y][x];
			cout << "YES\n" << cntr << '\n', ans.reserve(1 + cntr);

			while(cntr--)
			{
				ans.emplace_back(dir[i][j]);

				if(dir[i][j] == 'U') i++;
				else if(dir[i][j] == 'D') i--;
				else if(dir[i][j] == 'L') j++;
				else if(dir[i][j] == 'R') j--;
			}

			for(auto it = ans.rbegin(); it != ans.rend(); it++)
				cout << *it;

			cout << '\n';

			return 0;
		}
	}

	cout << "NO\n";

	// perform BFS starting from all monsters and find out the minimum time taken by ANY monster
	// to reach EVERY square (not including walls)

	// perform BFS for the player, while trying to reach any bordering side
	// if a square can be reached by a monster before the player or has a wall,
	// then it is unoptimal to go there

	// during BFS traversal, if a border comes in the way, we have succesfully found a solution
	// if this never occours, there is no possible solution

	return 0;
}