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

	int n, k; ll ans = 0; cin >> n >> k;
	vector<int> ar(n);
	map<int, int> chk;

	for(auto &e : ar)
		cin >> e;

	int i = 0, j = 0, cnt = 0;
	// I is the start of the current subarray (inclusive)
	// J is the end of the current subarray (inclusive)
	// cnt is the number of distinct elements in the current subarray

	// find left most i for every j such that the subarray has <= k distinct elements

	while(j < n)
	{
		cnt += (ll)(++chk[ar[j]] == 1);
		while(cnt > k)
			cnt -= (ll)(--chk[ar[i++]] == 0);
		ans += j - i + 1, j++;
	}

	cout << ans << '\n';

	return 0;
}