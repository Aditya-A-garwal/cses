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

struct event
{
	int a, b;
	ll c;

	bool operator<(const event &other) const
	{
		if(this->b == other.b)
			return this->a < other.a;
		return this->b < other.b;
	}

	bool operator>(const event &other) const
	{
		if(this->b == other.b)
			return this->a > other.a;
		return this->b > other.b;
	}
};

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<event> ar(n);
	vector<ll> dp(n, 0), pre(n);
	set<pair<int, int>, greater<>> chk;

	for(int i = 0; i < n; i++)
		cin >> ar[i].a >> ar[i].b >> ar[i].c;

	if(n == 1)
	{
		cout << ar[0].c << '\n';
		return 0;
	}

	sort(ar.begin(), ar.end());
	ll ans = dp[0] = pre[0] = ar[0].c;
	chk.insert({ar[0].b, 0});

	for(int i = 1; i < n; i++)
	{
		auto it = chk.upper_bound({ar[i].a, -1});
		if(it != chk.end())
			dp[i] = pre[(*it).ss];

		ans = max(ans, dp[i] += ar[i].c);
		pre[i] = max(pre[i-1], dp[i]);

		chk.insert({ar[i].b, i});
	}

	cout << ans << '\n';

	return 0;
}