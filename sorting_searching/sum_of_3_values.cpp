#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

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

	ll n, x; cin >> n >> x;
	vector<pair<ll, int>> ar(n);

	int a = 1;
	for(auto &e : ar) cin >> e.first, e.second = a++;
	sort(ar.begin(), ar.end());

	for(int k = 0; k < n-1; k++)
	{
		ll s = x - ar[k].first;
		int i = k+1, j = n-1;
		while(i < j)
		{
			ll y = ar[i].first + ar[j].first;
			if(y > s) j--;
			else if(y < s) i++;
			else
			{
				cout << ar[k].second << ' ' << ar[i].second << ' ' << ar[j].second << '\n';
				return 0;
			}
		}
	}

	cout << "IMPOSSIBLE\n";

	return 0;
}