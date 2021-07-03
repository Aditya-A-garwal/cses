#include<bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, five{0}, two{0}; cin >> n;

	for(int i = 2; i <= n; i *= 2)
		two += n / i;

	for(int i = 5; i <= n; i *= 5)
		five += n / i;

	cout << min(five, two) << '\n';

	return 0;
}