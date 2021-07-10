#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n, t; cin >> n >> t;

	vector<ll> ar(n);
	for(auto &e : ar) cin >> e;

	auto check = [&ar, &t](ll &x) -> bool
	{
		ll y{0};
		for(auto &e : ar)
		{
			y += x / e;
			if(y >= t) return 1;
		}
		return (y >= t);
	};

	ll lo{0}, hi{1e18 + 1}, ans;
	while(lo <= hi)
	{
		ll mid = lo + ((hi - lo + 1) >> 1);
		if(check(mid))
			hi = mid - 1, ans = mid;
		else
			lo = mid + 1;
	}

	cout << ans << '\n';

	return 0;
}