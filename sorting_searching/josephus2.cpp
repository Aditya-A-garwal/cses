#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ordered_set<int> people;
	int n, k, i; cin >> n >> k, i = k % n;
	for(int i = 1; i <= n; i++) people.insert(i);

	while(1)
	{
		int p = *(people.find_by_order(i));
		cout << p << ' ', people.erase(p);
		if(people.size()) i = (i + k) % people.size();
		else break;
	}

	return 0;
}