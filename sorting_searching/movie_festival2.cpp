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

	int n, k, ans = 0; cin >> n >> k;
	vector<pair<int, int>> ar(n);
	multiset<int, greater<>> check;
	multiset<int, greater<>>::iterator it;

	for(auto &[a, b] : ar)
		cin >> b >> a;

	for(int i = 0; i < k; i++)
		check.insert(-inf);

	sort(ar.begin(), ar.end());

	// Each person's ending time initially starts at -infinity (they can come for any movie)
	// we process each movie in the order of ending time
	// each time,w e find a person who's last movie has ended as close to the starting of this one
	// if no person exists whose movie has ended before this one starts, it is optimal to not watch this movie

	for(auto &[b, a] : ar)
	{
		it = check.lower_bound(a);
		if(it != check.end())
			ans++, check.erase(it), check.insert(b);
	}

	cout << ans << '\n';

	return 0;
}