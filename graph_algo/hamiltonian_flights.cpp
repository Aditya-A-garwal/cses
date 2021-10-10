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

int n, m;
int full;

vi adj[21];
int dp[2100000][21];

void toggleBit(int &mask, int i) {
	mask ^= (1 << i);
}

int getBit(int &mask, int i) {
	return (mask >> i) & 1;
}

int getNext(int i, int mask) {

	if(dp[mask][i] == -1) {

		ll res = 0;
		toggleBit(mask, i);

		for(auto &e : adj[i])
			if(!getBit(mask, e))
				(res += getNext(e, mask)) %= mod;

		toggleBit(mask, i);
		dp[mask][i] = res;
	}

	return dp[mask][i];
}

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

	int u, v;
	while(m--) {
		cin >> u >> v, --u, --v;
		adj[u].emplace_back(v);
	}

	cout << getNext(0, 0) << '\n';

	return 0;
}