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

	ll n, ans = 0, start = 0; cin >> n;
	vector<pair<ll, int>> tasks(n);

	for(auto &[x, y] : tasks)
		cin >> x >> y;

	sort(tasks.begin(), tasks.end());

	// we do the tasks in order of their deadlines,
	// if done in any other order, we will either lose as much time as we gain or more
	for(auto &[a, b] : tasks)
		start += a, ans += b - start;

	cout << ans << '\n';

	return 0;
}