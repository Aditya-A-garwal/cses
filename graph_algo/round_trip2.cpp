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

	int n, m; cin >> n >> m;
	vector<vector<int>> adjlst(n);
	vector<int> clr(n, 0), ans;

	// 0 is for unvisited
	// 1 is for currently checking descendants
	// 2 is for completely checked all descendants

	int a, b;
	while(m--)
	{
		cin >> a >> b;
		if(a != b)
			adjlst[--a].emplace_back(--b);
	}

	function<bool(int)> DFS = [&](int cur) -> bool
	{
		clr[cur] = 1;

		for(auto &nxt : adjlst[cur])
		{
			if(clr[nxt] == 0)
			{
				if(DFS(nxt))
				{
					ans.emplace_back(cur);
					if(ans[0] == cur)
					{
						cout << ans.size() << '\n';
						for(auto it = ans.rbegin(); it != ans.rend(); it++)
							cout << *it + 1 << ' ';
						cout << '\n';

						exit(0);
					}
					return 1;
				}
			}
			else if(clr[nxt] == 1)
			{

				ans.emplace_back(nxt);
				ans.emplace_back(cur);

				return 1;
			}
		}
		clr[cur] = 2;
		return 0;
	};

	for(int i = 0; i < n; i++)
	{
		if(!clr[i])
			DFS(i);
	}

	cout << "IMPOSSIBLE\n";

	return 0;
}