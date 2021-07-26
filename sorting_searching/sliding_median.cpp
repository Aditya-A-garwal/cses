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

	int n, k, mid; cin >> n >> k, mid = (k - 1)/2;
	vector<int> ar(n + 1); ar[0] = 0;
	ordered_set<pair<int, int>> chk;

	for(int i = 1; i <= n; i++)
		cin >> ar[i];

	for(int i = 1; i < k; i++)
		chk.insert({ar[i], i});

	for(int i = k; i <= n; i++)
	{
		chk.erase({ar[i - k], i-k}), chk.insert({ar[i], i});
		cout << (*chk.find_by_order(mid)).first << ' ';
	}

	cout << '\n';

	return 0;
}