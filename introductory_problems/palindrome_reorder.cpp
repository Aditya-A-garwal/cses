#include<bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string s, res = ""; cin >> s;

	int cnt[26];
	memset(cnt, 0, sizeof(cnt));

	for(auto &c : s) cnt[c - 'A']++;

	if(s.size() & 1)
	{
		// all letters must appear an even number of times except for one which
		// needs to appear an odd number of times

		int pivot = -1;

		for(int i = 0; i < 26; i++)
		{
			int &currCount = cnt[i];
			if(!currCount) continue;
			if(currCount & 1)
			{
				if(pivot != -1)
				{
					cout << "NO SOLUTION\n";
					return 0;
				}
				pivot = i;
			}
			currCount >>= 1;
			for(int x = 0; x < currCount; x++) res += (char)(i + 'A');
		}

		if(pivot == -1)
		{
			cout << "NO SOLUTION\n";
		}
		else
		{
			cout << res << (char)(pivot + 'A');
			reverse(res.begin(), res.end());
			cout << res << '\n';
		}
	}
	else
	{
		// All letter must appear an even number of times
		for(int i = 0; i < 26; i++)
		{
			int &currCount = cnt[i];
			if(!currCount) continue;
			if(currCount & 1)
			{
				cout << "NO SOLUTION\n";
				return 0;
			}
			currCount >>= 1;
			for(int x = 0; x < currCount; x++) res += (char)(i + 'A');
		}

		cout << res;
		reverse(res.begin(), res.end());
		cout << res << '\n';
	}

	return 0;
}