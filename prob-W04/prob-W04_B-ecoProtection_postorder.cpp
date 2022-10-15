#include<iostream>
#include <vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
vector<int>pl[100001];
vector<int>tr[100001];
bool virus[100001];
int par[100001];
int lca = 0;
int n, m, u, v;
void makeTree(int root) {
	int node = root;
	par[node] = 0;
	queue<int> q;
	q.push(node);
	while (!q.empty()) {
		node = q.front();
		q.pop();
		for (int i = 0; i < pl[node].size(); i++) {
			int cnode = pl[node][i];
			if (par[cnode] == 0 && cnode != 1) {
				tr[node].push_back(cnode);
				q.push(cnode);
				par[cnode] = node;
			}
		}
	}
}

int post(int vi) {
	int cnt = 0;
	if (virus[vi] == true) {
		cnt++;
	}
	for (int i = 0; i < tr[vi].size(); i++) {
			int cnode = tr[vi][i];
			cnt += post(cnode);
	}
	if (cnt == m) {
		lca = vi;
		cnt = m + 1;
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, tt = 0;
	cin >> t;
	while (t > tt) {
		cin >> n >> m;
		for (int i = 0; i < n-1; i++) {
			cin >> u >> v;
			pl[u].push_back(v);
			pl[v].push_back(u);
		}
		for (int i = 0; i < m; i++) {
			cin >> v;
			virus[v] = true;
		}
		makeTree(1);
		post(1);
		if (lca == 1) {
			cout << -1 << "\n";

		}
		else {
			if(par[lca]>lca)
				cout <<lca << " " << par[lca] << "\n";
			else {
				cout << par[lca] << " " << lca << "\n";
			}

		}
		for (int i = 0; i <= n ; i++) {
			tr[i].clear();
			pl[i].clear();
		}
		memset(virus, false, sizeof(virus));
		memset(par, 0, sizeof(par));
		tt++;
	}

	return 0;
}