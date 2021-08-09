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

	char c;
	int n, q, a, b; cin >> n >> q;

	ordered_set<pair<ll, int>> s;
	vector<int> ar(n);

	for(int i = 0; i < n; i++)
		cin >> ar[i], s.insert({ar[i], i});

	while(q--)
	{
		cin >> c >> a >> b;
		if(c == '?') // count between a and b
			cout << (s.order_of_key({b+1, -1}) - s.order_of_key({a, -1})) << '\n';
		else // change salary of employee a to b
		{
			--a;
			s.erase({ar[a], a});
			s.insert({ar[a] = b, a});
		}
	}

	return 0;
}
