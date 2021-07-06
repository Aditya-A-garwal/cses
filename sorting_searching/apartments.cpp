#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n, m, k, diff, ans{0}; cin >> n >> m >> k;
	vector<ll> a(n), b(m);

	for(auto &e : a) cin >> e;
	for(auto &e : b) cin >> e;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int i = 0, j = 0;
	while(i < n and j < m)
	{
		diff = a[i] - b[j];
		if(abs(diff) <= k) ans++, i++, j++; // found curr apt for curr user
		else if(diff > 0) j++; // user size too big, move to next apt
		else i++; // user size too small, move to next user
	}

	cout << ans << '\n';

	return 0;
}