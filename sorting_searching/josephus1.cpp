#include<bits/stdc++.h>
 
using namespace std;
 
int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);
 
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
	int n, k = 2; cin >> n;
 
	list<int> people;
	for(int i = 1; i <= n; i++) people.emplace_back(i);
 
	auto it = people.begin();
 
	while(n--)
	{
		for(int i = 1; i < k; i++)
			if(++it == people.end())
				it = people.begin();
 
		cout << *it << ' ';
 
		it = people.erase(it);
		if(it == people.end())
			it = people.begin();
	}
 
	return 0;
}