#include<bits/stdc++.h>
using namespace std;
vector<int>tree[1000005];
int ct[1000005] = {0};
void dfs(int src, int end) {
	ct[src] = 1;
	for (auto child : tree[src]) {
		if (child == end)continue;
		dfs(child, src);
		ct[src] += ct[child];
	}
}
int main() {

	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int data; cin >> data;
		tree[data].push_back(i);
	}

	dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		cout << ct[i] - 1 << " " ;
	}


	return 0;
}