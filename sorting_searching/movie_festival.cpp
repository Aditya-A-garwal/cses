#include<bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, ans = 1; cin >> n;
	vector<pair<int, int>> ar(n);

	for(auto &[a, b]: ar) cin >> b >> a;
	sort(ar.begin(), ar.end());

	int last = 0;

	for(int i = 1; i < n; i++)
	{
		if(ar[last].first <= ar[i].second)
			ans++, last = i;
	}

	cout << ans << '\n';

	return 0;
}