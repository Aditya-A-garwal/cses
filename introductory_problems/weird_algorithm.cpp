#include<bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);

	long long n; cin >> n;

	cout << n;

	while(n > 1)
		cout << ' ' << (n = ((n & 1)?(1 + 3*n):(n >> 1)));

	return 0;
}