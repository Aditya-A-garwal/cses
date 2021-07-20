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

	ll n, x; cin >> n >> x;

	map<int, pii> exists;
	vector<int> ar(n);

	if(n < 4)
		goto label;

	for(auto &e : ar)
		cin >> e;

	for(int i = 0; i < n; i++)
	{
		for(int j = i+1; j < n; j++)
		{
			int target = x - ar[i] - ar[j];
			map<int, pii>::iterator it = exists.find(target);

			if(target >= 0 and it != exists.end())
			{
				auto [k, l] = (*it).ss;
				cout << k + 1 << ' ' << l + 1 << ' ' << i + 1 << ' ' << j + 1 << '\n';
				return 0;
			}
		}

		for(int j = 0; j < i; j++)
			exists[ar[j] + ar[i]] = {j, i};
	}


	label:	cout << "IMPOSSIBLE\n";

	return 0;
}