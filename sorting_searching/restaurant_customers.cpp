#include<bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, ans = 0; cin >> n;
	vector<pair<int, bool>> ar;
	ar.reserve(2*n + 1);

	for(int i = 0; i < n; i++)
	{
		int x, y; cin >> x >> y;
		ar.emplace_back(x, 1);
		ar.emplace_back(y, 0);
	}
	sort(ar.begin(), ar.end());

	int curr = 0;
	for(auto &e : ar)
	{
		if(e.second) curr++;
		else curr--;
		ans = max(ans, curr);
	}

	cout << ans << '\n';


	return 0;
}