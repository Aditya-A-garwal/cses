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

	vector<vector<int>> adjlst1(n), adjlst2(n);
	vector<int> vis(n, 0);

	while(m--)
	{
		int a, b; cin >> a >> b, --a, --b;
		adjlst1[a].emplace_back(b), adjlst2[b].emplace_back(a);
	}

	stack<int> st;
	vis[0] = 1, st.emplace(0);

	while(!st.empty())
	{
		int h = st.top(); st.pop();

		for(auto &e : adjlst1[h])
			if(vis[e] != 1)
				vis[e] = 1, st.emplace(e);
	}

	for(int i = 0; i < n; i++)
	{
		if(vis[i] != 1)
		{
			cout << "NO\n" << 1 << ' ' << ++i << '\n';
			return 0;
		}
	}

	vis[0] = 2, st.emplace(0);

	while(!st.empty())
	{
		int h = st.top(); st.pop();

		for(auto &e : adjlst2[h])
			if(vis[e] != 2)
				vis[e] = 2, st.emplace(e);
	}

	for(int i = 0; i < n; i++)
	{
		if(vis[i] != 2)
		{
			cout << "NO\n" << ++i << ' ' << 1 << '\n';
			return 0;
		}
	}

	cout << "YES\n";

	return 0;
}