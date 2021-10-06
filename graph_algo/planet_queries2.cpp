#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vi = vector<int>;
using vll = vector<ll>;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int inf = 1e9 + 10;
const ll llinf = 1e18 + 10;

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	const int mxLog = 20;

	int n, q, a, b, whichcomp; cin >> n >> q;

	vector<array<int, mxLog>> pre(n);
	vector<vi> adj(n);

	vi comp(n);
	vi oncycle(n, -1);
	vi depth(n, 0);

	// size should be number of components
	vi compvis(n);
	vi cyclelen(n);

	stack<int> st;

	auto ances = [&](int node, int k) -> int {

		for(int i = 0; i < mxLog; i++)
			if(k & (1 << i))
				node = pre[node][i];

		return node;
	};

	// contruct adjacency list and predecessor structures
	for(int i = 0; i < n; i++) {
		cin >> pre[i][0], --pre[i][0];
		adj[i].emplace_back(pre[i][0]),
		adj[pre[i][0]].emplace_back(i);
	}

	// calculate predecessor table
	for(int j = 1; j < mxLog; j++)
		for(int i = 0; i < n; i++)
			pre[i][j] = pre[pre[i][j-1]][j-1];

	// assign components
	for(int i = 0, compCntr = 0, h; i < n; i++) {
		if(comp[i])
			continue;
		comp[i] = ++compCntr, st.emplace(i);
		while(!st.empty()) {
			h = st.top(), st.pop();
			for(auto &e : adj[h])
				if(!comp[e])
					comp[e] = compCntr, st.emplace(e);
		}
	}

	// use floyd's algorith for each component to find
	//  - cyclic nodes and index of nodes in cycle
	//  - size of cycle

	for(int i = 0, ptr1, ptr2, k; i < n; i++) {
		if(compvis[comp[i]])
			continue;

		compvis[comp[i]] = 1;

		ptr1 = pre[i][0], ptr2 = pre[i][1];
		while(ptr1 != ptr2) {
			ptr1 = pre[ptr1][0];
			ptr2 = pre[ptr2][1];
		}

		k = 0;
		do {
			oncycle[ptr1] = k++;
			ptr1 = pre[ptr1][0];
		} while(ptr1 != ptr2);

		cyclelen[comp[i]] = k;
	}

	// assign a depth for all non-cyclic nodes
	// using depth, it becomes possible to find out if two non-cyclic nodes in the same component can
	// be accessed from one another
	for(int i = 0, h; i < n; i++) {
		if(oncycle[i] == -1)
			continue;

		depth[i] = 0, st.emplace(i);
		while(!st.empty()) {
			h = st.top(), st.pop();
			for(auto &e : adj[h]) {
				if(oncycle[e] == -1 and depth[e] == 0)
					depth[e] = depth[h] + 1, st.emplace(e);
			}
		}

	}

	while(q--) {
		cin >> a >> b, --a, --b;

		// the nodes arent in the same component
		if(comp[a] != comp[b]) {
			cout << -1 << '\n';
			continue;
		}

		whichcomp = comp[a];

		// both are acyclic nodes
		if(oncycle[a] == -1 and oncycle[b] == -1) {
			if(depth[a] < depth[b]) {
				cout << -1 << '\n';
				continue;
			}
			else {
				int diff = depth[a] - depth[b];
				if(b != ances(a, diff))
					cout << -1 << '\n';
				else
					cout << diff << '\n';
			}
		}

		// source is acyclic target is cyclic
		else if(oncycle[a] == -1 and oncycle[b] != -1) {

			// find out my first ancestor which is cyclic
			int fcyclic = ances(a, depth[a]);
			int diff = (oncycle[b] - oncycle[fcyclic] + cyclelen[whichcomp]) % cyclelen[whichcomp];

			cout << depth[a] + diff << '\n';
		}

		// source is cyclic target is non-cyclic
		else if(oncycle[a] != -1 and oncycle[b] == -1) {
			cout << -1 << '\n';
		}

		// both are cyclic nodes
		else {
			int diff = (oncycle[b] - oncycle[a] + cyclelen[whichcomp]) % cyclelen[whichcomp];
			cout << diff << '\n';
		}
	}

	return 0;
}