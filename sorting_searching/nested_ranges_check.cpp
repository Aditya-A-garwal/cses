#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
	vector<int> parents(n), children(n);
	vector<array<int, 3>> ar(n);

	ordered_set<array<int, 2>> s;

	for(int i = 0; i < n; i++)
		cin >> ar[i][0] >> ar[i][1], ar[i][2] = i;

	sort(ar.begin(), ar.end(), [](const array<int, 3> i, const array<int, 3> j)
	{
		// If the starting index is equal, the bigger one should come first
		if(i[0] == j[0])
			return i[1] > j[1];
		// Order based on starting index
		return i[0] < j[0];
	});

	// Calculate my parents
	for(int i = 0; i < n; i++)
	{
		parents[ar[i][2]] = i - s.order_of_key({ar[i][1], -1});
		s.insert({ar[i][1], i});
	}

	s.clear();

	// Calculate my children
	for(int i = n-1; i >= 0; i--)
	{
		children[ar[i][2]] = s.order_of_key({ar[i][1]+1, -1});
		s.insert({ar[i][1], n-1-i});
	}

	for(auto &e : children) cout << (e!=0) << ' ';
	cout << '\n';
	for(auto &e : parents) cout << (e!=0) << ' ';
	cout << '\n';

	return 0;
}