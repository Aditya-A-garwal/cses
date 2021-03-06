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

const int inf = 1e9 + 1;
const ll llinf = 200000000000002;

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;
	vector<ll> ar(n);

	for(auto &e : ar)
		cin >> e;

	auto check = [&](ll s) -> bool
	{
		ll cursum = 0, subs = 1;
		for(auto &e : ar)
		{
			if(e > s)
				return 0;
			if(cursum + e > s)
				cursum = 0, subs++;

			cursum += e;
		}

		return subs <= k;
	};

	ll lo = n, hi = (ll)n * inf, mid, ans;

	while(lo <= hi)
	{
		mid = lo + (hi - lo + 1)/2;
		if(check(mid))
			hi = mid - 1, ans = mid;
		else
			lo = mid + 1;
	}

	cout << ans << '\n';

	return 0;
}