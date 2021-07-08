#include<bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, x, ans = 0; cin >> n;
	vector<bool> hasCome(n + 1, 0);

	for(int i = 0; i < n; i++)
		cin >> x, ans += 1 - (int)hasCome[x-1], hasCome[x] = 1;

	cout << ans << '\n';

	return 0;
}