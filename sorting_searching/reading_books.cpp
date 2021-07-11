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

	int n; cin >> n;	
	ll sum = 0, mx = -1, x;

	// If the greatest book takes longer to read than all the others combined, and it has to be read
	// by both the people then it will be the bottleneck
	// otherwise all books can always be read in some order by the two so that they do not overlap

	for(int i = 0; i < n; i++)
		cin >> x, sum += x, mx = max(mx, x);

	cout << ((mx > sum-mx)?(2*mx):(sum)) << '\n';

	return 0;
}
