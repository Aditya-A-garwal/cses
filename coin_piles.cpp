#include<bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	// the first operation is perform x times and second y times (order does not matter)
	// pile 1 will have a-x-2y coins
	// pile 2 will have b-2x-y coins
	// if the operations are POSSIBLE and performed OPTIMALLY, both the piles must have
	// 0 coins remaining, therefore-

	// x+2y-a = 0
	// 2x+y-b = 0

	// x = (b1c2-b2c1)/(a1b2-a2b1) = (2b - a)/3
	// y = (c1a2-c2a1)/(a1b2-a2b1) = (2a - b)/3

	int t; cin >> t;
	while(t--)
	{
		long long a, b, x, y; cin >> a >> b, x = 2*b - a, y = 2*a - b;
		puts((x < 0 or y < 0 or x%3 or y%3)?"NO":"YES");
	}
	return 0;
}