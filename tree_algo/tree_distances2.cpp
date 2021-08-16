#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vi = vector<int>;
using vll = vector<ll>;

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

	// root the tree at some arbitrary node (0 in this example)
	// perform DFS to get the number of nodes in each subtree and the depth of each node
	// every time we move from a node X to its neighbour Y,

	int n; cin >> n;
	vector<vi> adjlst(n);
	vi depth(n), num(n);
	vll ans(n, 0);

	for(int i = 1, a, b; i < n; i++)
	{
		cin >> a >> b, --a, --b;
		adjlst[a].emplace_back(b), adjlst[b].emplace_back(a);
	}

	function<int(int, int)> DFS = [&](int cur, int prv) -> int
	{
		num[cur] = 0, ans[0] += depth[cur];

		for(auto &nxt : adjlst[cur])
		{
			if(nxt == prv)
				continue;
			depth[nxt] = 1 + depth[cur];
			num[cur] += 1 + DFS(nxt, cur);
		}

		return num[cur];
	};

	depth[0] = 0, DFS(0, -1);

	stack<pii> st;
	st.emplace(0, -1);

	int cur, prv;
	while(!st.empty())
	{
		tie(cur, prv) = st.top(), st.pop();

		for(auto &nxt : adjlst[cur])
		{
			if(nxt == prv)
				continue;

			ans[nxt] = ans[cur] - 1;
			ans[nxt] += n - (num[nxt] << 1) - 1;
			st.emplace(nxt, cur);
		}
	}

	for(auto &e : ans)
		cout << e << ' ';

	cout << '\n';

	return 0;
}
