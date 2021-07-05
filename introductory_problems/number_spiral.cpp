#include<bits/stdc++.h>

using namespace std;

void testCase()
{
	unsigned long long x, y, ans; cin >> y >> x;

	if(x > y)
	{
		if(x & 1)
			ans = x * x - y + 1;
		else
			ans = (x - 1) * (x - 1) + y;
	}
	else if(y > x)
	{
		if(y & 1)
			ans = (y - 1) * (y - 1) + x; 
		else
			ans = y * y - x + 1;
	}
	else
		ans = 1 + x*(x - 1);

	cout << ans << endl;
}

int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);

	int t; cin >> t;
	while(t--) testCase();

	return 0;
}