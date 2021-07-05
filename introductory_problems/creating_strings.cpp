#include<bits/stdc++.h>

using namespace std;

string s;
vector<string> res;

inline bool validSwap(int start, int curr)
{
	for(int i = start; i < curr; i++)
		if(s[i] == s[curr]) return 0;
	return 1;
}

void permute(int l, int r)
{
	if(l >= r)
		res.emplace_back(s);
	else
	{
		for(int i = l; i <= r; i++)
		{
			if(validSwap(l, i))
			{
				swap(s[l], s[i]);
				permute(l+1, r);
				swap(s[l], s[i]);
			}
		}
	}
}

int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	auto fact = [](int x)
	{
		int ans{1};
		for(int i = 1; i <= x; i++) ans *= i;
		return ans;
	};

	cin >> s;

	int cntr[26]={}, posib = fact(s.size());
	for(const char &c : s) cntr[c - 'a']++;
	for(int i = 0; i < 26; i++) posib /= fact(cntr[i]);

	cout << posib++ << '\n';

	res.reserve(posib);
	permute(0, s.size() - 1);

	sort(res.begin(), res.end());
	for(auto &c : res) cout << c << '\n';

	return 0;
}