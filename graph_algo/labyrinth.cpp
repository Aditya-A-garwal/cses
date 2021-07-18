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

const int inf = 1e9 + 1;

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	pair<int, int> dirs[]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	char dirLabels[]{"UDLR"};

	queue<pair<int, int>> coors;
	vector<char> ans;

	int n, m, si, sj, ei, ej; char c; cin >> n >> m;

	vector<vector<pair<int, char>>> ar(n + 2, vector<pair<int, char>>(m + 2, {-1, '-'}));

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin >> c;
			if(c != '#')
			{
				ar[i][j].ff = inf;
				if(c == 'A') si = i, sj = j;
				else if(c == 'B') ei = i, ej = j;
			}
		}
	}

	ar[si][sj].ff = 0, coors.push({si, sj});

	while(!coors.empty())
	{
		auto [i, j] = coors.front(); coors.pop();

		for(int cntr = 0; cntr < 4; cntr++)
		{
			auto [y, x] = dirs[cntr];

			if((1 + ar[i][j].ff) < ar[i + y][j + x].ff)
			{
				ar[i + y][j + x].ff = 1 + ar[i][j].ff, coors.emplace(i + y, j + x);
				ar[i + y][j + x].ss = dirLabels[cntr];
			}
		}

		if(i == ei and j == ej) break;
	}

	if(ar[ei][ej].ff < inf)
	{
		int i = ei, j = ej;
		while(1)
		{
			ans.emplace_back(ar[i][j].ss);

			if(ar[i][j].ss == 'U') i++;
			else if(ar[i][j].ss == 'L') j++;
			else if(ar[i][j].ss == 'R') j--;
			else if(ar[i][j].ss == 'D') i--;

			if(i == si and j == sj) break;
		}
		cout << "YES\n" << ans.size() << '\n';
		for(auto it = ans.rbegin(); it != ans.rend(); it++) cout << *it;
		cout << '\n';
	}
	else
		cout << "NO\n";

	return 0;
}