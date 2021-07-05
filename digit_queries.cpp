#include<bits/stdc++.h>
 
#define ll long long
 
using namespace std;
 
int main(int argc, char *argv[])
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
 
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
	ll q, k; cin >> q;
 
	while(q--)
	{
		cin >> k;
		if(k <= 9)
		{
			cout << k << '\n';
			continue;
		}
 
		ll blockLen = 0, blockStart = 1, numCharsPast = 0;
 
		while(1)
		{
			ll temp = numCharsPast + (blockStart * 9)*++blockLen;
			if(temp >= k) break;
			numCharsPast = temp, blockStart *= 10;
		}
 
		ll x = blockStart + (k - numCharsPast - 1)/blockLen;
		k = blockLen - (k - (numCharsPast + (x-blockStart)*blockLen));
 
		for(int i = 0; i < k; i++) x /= 10;
		cout << x % 10 << endl;
	}
 
	return 0;
}