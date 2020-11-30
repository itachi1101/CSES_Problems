#include<bits/stdc++.h>
using namespace std;
vector<int>v[1000005];
int ct[1000005] = {0};
int dist[1000005] = {0};
int vis[1000005] = {0};
int node = -1;
int path = INT_MIN;
void dfs(int src) {
	vis[src] = 1;
	for (auto child : v[src]) {
		if (vis[child] == 0) {
			dist[child] = dist[src] + 1;
			if (dist[child] > path) {
				path = dist[child];
				node = child;
			}
			dfs(child);
		}
	}
}
int used[1000005] = {0};
int d[1000005] = {0};
int new_node = -1;
int new_distance = INT_MIN;
void dfs2(int src) {
	used[src] = 1;
	for (auto child : v[src]) {
		if (used[child] == 0) {
			d[child] = d[src] + 1;
			if (d[child] > new_distance) {
				new_distance = d[child];
				new_node = child;
			}
			dfs2(child);
		}
	}
}
int main() {

	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	dfs2(node);
	cout << d[new_node];
	return 0;
}