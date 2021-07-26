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

	ll n, k, ls = 0, hs = 0, lsz, hsz; cin >> n >> k, hsz = k/2, lsz = k - hsz;
	vector<ll> ar(n + 1); ar[0] = 0;
	multiset<ll> lo, hi;

	if(k == 1)
	{
		for(int i = 0; i < n; i++)
			cout << "0 ";
		cout << '\n';
		return 0;
	}

	auto insert = [&](ll x)
	{
		auto it = hi.begin();
		if(*it > x)
			ls += x, lo.insert(x);
		else
			hs += x, hi.insert(x);
	};

	auto erase = [&](int x)
	{
		auto it = hi.begin();
		if(*it > x)
			ls -= x, lo.erase(lo.find(x));
		else
			hs -= x, hi.erase(hi.find(x));
	};

	auto balance = [&]()
	{
		while(hi.size() > hsz)
		{
			auto it = hi.begin();
			ls += *it, hs -= *it;
			lo.insert(*it), hi.erase(it);
		}
		while(lo.size() > lsz)
		{
			auto it = lo.rbegin();
			ls -= *it, hs += *it;
			hi.insert(*it), lo.erase(lo.find(*it));
		}
	};

	for(int i = 1; i <= n; i++)
		cin >> ar[i];

	for(int i = 0; i < k; i++)
		hs += ar[i], hi.insert(ar[i]);

	balance();

	for(int i = k; i <= n; i++)
	{
		insert(ar[i]), erase(ar[i - k]), balance();

		ll med = (k & 1)?(*(lo.rbegin())):0;
		cout << hs - ls + med << ' ';
	}

	cout << '\n';

	return 0;
}
