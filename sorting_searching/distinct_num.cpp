#include<bits/stdc++.h>

using namespace std;

// bitset<1000000002> check;

int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	// SLOW SOLUTION
	// int n, x, ans = 0; cin >> n;

	// for(int i = 0; i < n; i++)
	// {
	// 	cin >> x;
	// 	if(check[x] == 0) ans++, check[x] = 1;
	// }

	// cout << ans << '\n';

	// FASTER SOLUTION
	int n, ans = 1; cin >> n;
	vector<int> ar(n);
	for(auto &e : ar) cin >> e;

	sort(ar.begin(), ar.end());
	for(auto it = ar.begin() + 1; it != ar.end(); it++)
		ans += (int)(*it != *(it - 1));

	cout << ans << '\n';

	// ALTERNATE SOLUTION
	// int n, x; cin >> n;
	// set<int> s;

	// for(int i = 0; i < n; i++) cin >> x, s.insert(x);
	
	// cout << s.size() << '\n';

	return 0;
}