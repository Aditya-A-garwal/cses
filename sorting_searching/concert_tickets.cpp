#include<bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	multiset<int, greater<>> tickets;

	for(int i = 0; i < n; i++)
	{
		int x; cin >> x;
		tickets.insert(x);
	}

	for(int i = 0; i < m; i++)
	{
		int x; cin >> x;
		auto it = tickets.lower_bound(x);
		if(it == tickets.end()) cout << -1;
		else cout << *it, tickets.erase(it);
		cout << '\n';
	}

	return 0;
}