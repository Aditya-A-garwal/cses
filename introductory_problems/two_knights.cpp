#include<bits/stdc++.h>

#define ull unsigned long long

using namespace std;

int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);

	ull n; cin >> n;
	for(ull k = 1; k <= n; k++)
	{
		ull total = ((k * k) * ((k * k) - 1))>>1;
		ull invalid = ((k-1)*(k-2))<<2;
		cout << total - invalid << "\n";
	}

	return 0;
}