#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define check_bit(var, bit) (var & (1 << (bit)))

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int inf = 1e9 + 10;
const ll llinf = 1e18 + 10;

const ll mod = 1e9 + 7;

ll n, m;
vector<vector<ll>> dp;

void getNext(vector<int> &nxtPossib, int mask, int pos = 0, int nxt = 0)
{
	if(pos >= n)
	{
		nxtPossib.emplace_back(nxt);
		return;
	}

	// if the current position is filled then dont add anything
	if(check_bit(mask, pos))
		getNext(nxtPossib, mask, pos + 1, nxt);

	else
	{
		// if the current position is not filled, it is always possible to put in a right facing tile
		getNext(nxtPossib, mask, pos + 1, nxt | (1 << pos));

		// if the current and next positions are not filled, it is also possible to put a down facing tile
		if(pos < n-1 and !check_bit(mask, pos + 1))
			getNext(nxtPossib, mask, pos + 2, nxt);
	}
}

ll solve(int col, int mask)
{
	if(col >= m)
		return (ll)(mask == 0);

	// if not calculated then calculate first
	if(dp[col][mask] == -1)
	{
		ll res = 0;
		vector<int> nxtPossib;

		// get all next possible masks based on the current one
		getNext(nxtPossib, mask);

		for(int &nxt : nxtPossib)
			(res += solve(col + 1, nxt)) %= mod;

		dp[col][mask] = res;
	}

	return dp[col][mask];
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	if(n > m)
		swap(n, m);

	dp = vector<vector<ll>>(m, vector<ll>(1 << n, -1));

	cout << solve(0, 0) << '\n';

	return 0;
}