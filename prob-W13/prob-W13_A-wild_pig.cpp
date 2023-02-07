#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<set>
#include<algorithm>
#include<stack>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;
vector<pair<int,int>> road[1001];
vector<pair<int,int>> h;
bool visit[1001];
int height[1001];
void reset() {
	h.clear();
//	inhateam.clear();
//	play.clear();
//	chk.clear();
//	//while (!pq.empty()) {
//	//	pq.pop();
//	//}
	for (int i = 0; i < 1001; i++) {
		road[i].clear();
	}
	memset(visit, 0, sizeof(visit));
}

void DFS(int node) {
	stack<int> s;
	s.push(node);
	while (!s.empty()) {
		node = s.top();
		s.pop();
		if (visit[node]) {
		}
		else {
			visit[node] = true;
			cout << node << "\n";
			sort(road[node].begin(), road[node].end(),greater<>());
			for (int i = 0; i < road[node].size(); i++) {
				int cnode = road[node][i].second;
				if (!visit[cnode]) {
					s.push(cnode);
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("prob-W13/sample-W13_A.1.in", "r", stdin);
	int t, tt = 0;
	cin >> t;
	while (t > tt) {
		int n,m;
		cin >> n >> m;
		int val;
		for (int i = 0; i < n; i++) {
			cin >> val;
			height[i] = val;
			h.push_back({val,i});
		}
		int i, j;
		for (int k = 0; k < m; k++) {
			cin >> i >> j;
			road[i].push_back({ height[j], j });
			road[j].push_back({ height[i],i });
		}
		sort(h.begin(), h.end());
		for (int i = 0; i < h.size(); i++) {
			if (visit[h[i].second]) {
				continue;
			}
			DFS(h[i].second);
		}
		reset();
		tt++;
	}

	return 0;
}
