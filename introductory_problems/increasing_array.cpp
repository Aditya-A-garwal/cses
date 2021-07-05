#include<bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);

	int n; cin >> n;
	unsigned long long ans{0};
	int prv; cin >> prv;

	for(int i = 1; i < n; i++)
	{
		int x; cin >> x;
		if(x < prv) ans += prv - x, x = prv;
		prv = x;
	}

	cout << ans;

	return 0;
}