#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define ff first
#define ss second

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
	vector<pii> vis(n, {-1, -1});

	stack<int> st;

	while(m--)
	{
		int x, y; cin >> x >> y;
		adjlst[--x].emplace_back(--y);
	}

	vis[0] = {-1, 0}, st.emplace(0);
	int h;

	while(!st.empty())
	{
		h = st.top(), st.pop();

		for(auto &nxt : adjlst[h])
			if(vis[nxt].ss < 1 + vis[h].ss)
				vis[nxt] = {h, 1 + vis[h].ss}, st.emplace(nxt);
	}

	if(vis[n-1].ff == -1)
	{
		cout << "IMPOSSIBLE\n";
		return 0;
	}

	vector<int> ans; ans.reserve(vis[n-1].ss + 1);

	int i = n-1;
	while(i != -1)
		ans.emplace_back(i), i = vis[i].ff;

	cout << ans.size() << '\n';
	for(auto it = ans.rbegin(); it != ans.rend(); it++)
		cout << 1 + *it << ' ';
	cout << '\n';

	return 0;
}