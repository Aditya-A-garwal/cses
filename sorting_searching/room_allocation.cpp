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

	set<int> rooms;
	set<int>::iterator it;

	int n, cnt = -1; cin >> n;
	vector<int> ans(n);
	vector<array<int, 3>> people;
	people.reserve(1 + (n << 1));

	for(int i = 0; i < n; i++)
	{
		int x, y; cin >> x >> y;
		people.push_back({x, 0, i});
		people.push_back({y, 1, i});

		rooms.insert(i + 1);
	}

	sort(people.begin(), people.end());

	for(auto &[a, b, c] : people)
	{
		if(b == 0) // coming
		{
			it = rooms.begin();
			ans[c] = *it;
			cnt = max(cnt, ans[c]);
			rooms.erase(it);
		}
		else // going
			rooms.insert(ans[c]);
	}

	cout << cnt << '\n';

	for(auto &e : ans) cout << e << ' ';
	cout << '\n';

	return 0;
}