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

	int n, x, tn, cnt, wt; cin >> n >> x, tn = 1 << n;
	vector<int> ar(n);
	vector<pii> dp(tn, {inf, inf});
	dp[0] = {0, inf};

	for(auto &e : ar)
		cin >> e;

	for(int s = 1; s < tn; s++)
	{
		for(int i = 0, p = 1; i < n; i++, p <<= 1)
		{
			if((s&p) == 0)
				continue;

			tie(cnt, wt) = dp[s^p];
			if(wt + ar[i] > x)
				wt = min(wt, ar[i]), cnt++;
			else
				wt += ar[i];

			dp[s] = min(dp[s], {cnt, wt});
		}
	}

	// dp[P] = minimum number of trips required if those items are included whose corresponding bits
	// are set in P along with the weight of the smallest set
	// to get to a state P, we go through every state p such that setting a specific bit in p to 1
	// makes it equal to P
	// this denotes checking each set of items to which adding one will result in the current set

	// if it is possible to add the current person to set p without exceeding the max weight, do so
	// otherwise increase the count
	// also check if it is optimal to choose the previous set as new smallest set or the new person

	// check if the current count and weight are more optimal than the previous one and allocate accordingly

	cout << dp[tn - 1].first << '\n';

	return 0;
}