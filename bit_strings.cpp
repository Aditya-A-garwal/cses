#include<bits/stdc++.h>

#define ull unsigned long long
#define MOD 1000000007

using namespace std;

int main(int argc, char *argv[])
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	ull n, ans{1}, x{2}; cin >> n;

	while(n)
	{
		if(n & 1) ans = (ans * x) % MOD;
		n >>= 1, x = (x * x) % MOD;
	}

	cout << ans << '\n';

	return 0;
}