#include<bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
	// freopen("../input.txt", "r", stdin);
	// freopen("../output.txt", "w", stdout);

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int x, n; cin >> x >> n;

	set<pair<int, int>, greater<>> segments;
	multiset<int, greater<>> sz;
	set<pair<int, int>>::iterator it;

	segments.insert({0, x});
	sz.insert(x);

	for(int i = 0, p; i < n; i++)
	{
		cin >> p;

		it = segments.upper_bound({p, 0});
		if(it != segments.end())
		{
			pair<int, int> a{(*it).first, p}, b{p, (*it).second};

			sz.erase(sz.find((*it).second - (*it).first));
			segments.erase(it);

			segments.insert(a), segments.insert(b);
			sz.insert(b.second - b.first), sz.insert(a.second - a.first);
		}

		cout << *(sz.begin()) << ' ';
	}
	cout << '\n';

	// SLOWER MORE INTUITIVE PROGRAM
	// set<pair<int, int>, greater<>> segments;
	// multiset<pair<int, int>, szComp> szSegments;
	// set<pair<int, int>>::iterator it;
 
	// segments.insert({0, x});
	// szSegments.insert({0, x});
 
	// for(int i = 0, p; i < n; i++)
	// {
	// 	cin >> p;
 
	// 	it = segments.upper_bound({p, 0});
	// 	if(it != segments.end())
	// 	{
	// 		pair<int, int> a{(*it).first, p}, b{p, (*it).second};
 
	// 		szSegments.erase(szSegments.find(*it));
	// 		segments.erase(it);
 
	// 		segments.insert(a);
	// 		segments.insert(b);
 
	// 		szSegments.insert(a);
	// 		szSegments.insert(b);
	// 	}
 
	// 	it = szSegments.begin();
 
	// 	cout << (*it).second - (*it).first << ' ';
	// }
	// cout << '\n';

	return 0;
}