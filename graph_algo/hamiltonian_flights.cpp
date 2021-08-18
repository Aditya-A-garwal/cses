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

const int mod = 1e9 + 7;

ll n, m, full;

vi adj[21];

int dp[2097152][21];

inline void toggleVis(int node, int &mask)
{
	mask ^= (1 << node);
}

inline int getVis(int node, int &mask)
{
	return (mask >> node) & 1;
}

int getNext(int mask, int cur)
{
	if(dp[mask][cur] == -1)
	{
		ll res = 0;

		toggleVis(cur, mask);

		for(auto &e : adj[cur])
		{
			if(getVis(e, mask))
				continue;
			(res += getNext(mask, e)) %= mod;
		}

		toggleVis(cur, mask);
		dp[mask][cur] = res;
	}

	return dp[mask][cur];
}

// dp[i][j] is the ans for the sub problem-
// the nodes in the bit representation of "i" have been used up
// j is the current node

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m, full = (1 << (n - 1)) - 1;
	memset(dp, -1, sizeof(dp));

	dp[full][n-1] = 1;

	int a, b;
	while(m--)
	{
		cin >> a >> b, --a, --b;
		adj[a].emplace_back(b);
	}

	cout << getNext(0, 0) << '\n';

	return 0;
}