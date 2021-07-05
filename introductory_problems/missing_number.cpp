#include<bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);

	long long n, x, s; cin >> n, s = n*(n+1)/2;

	for(int i = 1; i < n; i++)
		cin >> x, s -= x;

	cout << s;

	return 0;
}