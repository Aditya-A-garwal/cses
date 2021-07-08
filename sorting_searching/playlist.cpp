#include<bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, ans = 1; cin >> n;
	map<int, int> pos;

	for(int i = 0, j = 0, x; i < n; i++)
	{
		cin >> x;
		j = max(j, pos[x]), ans = max(ans, 1 + i - j);
		pos[x] = 1 + i;
	}

	cout << ans << '\n';

	return 0;
}