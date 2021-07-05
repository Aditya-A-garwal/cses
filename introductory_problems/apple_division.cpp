#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n, x, mindiff{0x7fffffffffffffff}; cin >> n, x = -1 + (1 << n);
	vector<ll> weights(n);

	for(ll &a : weights) cin >> a;

	for(int i = 0; i <= x; i++)
	{
		ll w[2]{0, 0};
		for(int j = 0; j < n; j++)
			w[(i >> j) & 1] += weights[j];

		mindiff = min(mindiff, abs(w[1] - w[0]));
	}

	cout << mindiff << '\n';

	return 0;
}