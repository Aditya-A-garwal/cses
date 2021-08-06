#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

#define ll long long

using namespace std;

string c;
ll dp[20][10][2][2];

ll solve(short n, short pre, short tight, short prz)
{

	// n is the position of the current digit in this function call (0 indexed from the left)
	// pre is the previous digit in the number
	// tight is if the current digit is bound to be less than the corresponding digit of string
	// prz is if the current number has only got 0s

	if(n >= c.size())
		return 1;

	if(dp[n][pre][tight][prz] == -1)
	{
		short top = (short)((tight)?(c[n] - '0'):(9));

		ll res = 0;

		for(int i = 0; i <= top; i++)
			if(pre != i or prz)
				res += solve(n + 1, i, tight & (i == top), prz & (i == 0));

		dp[n][pre][tight][prz] = res;
	}

	return dp[n][pre][tight][prz];
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll a, b; cin >> a >> b;

	c = to_string(b), memset(dp, -1, sizeof(dp));
	ll x = solve(0, 0, 1, 1);

	c = to_string(a - 1), memset(dp, -1, sizeof(dp));
	ll y = solve(0, 0, 1, 1);

	cout << x - y << '\n';

	return 0;
}