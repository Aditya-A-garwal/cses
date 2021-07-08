#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	ll ans = numeric_limits<ll>::min();
	vector<ll> ar(n + 1), premin(n + 1);

	ar[0] = premin[0] = 0;

	for(int i = 1; i <= n; i++)
		cin >> ar[i], ar[i] += ar[i-1];

	for(int i = 1; i <= n; i++)
		premin[i] = min(ar[i], premin[i-1]);

	for(int i = 0; i < n; i++)
		ans = max(ans, ar[i + 1] - premin[i]);

	cout << ans << '\n';

	return 0;
}