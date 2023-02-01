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
int fare[251][251];

void reset() {
	//h.clear();
//	inhateam.clear();
//	play.clear();
//	chk.clear();
//	//while (!pq.empty()) {
//	//	pq.pop();
//	//}
	//for (int i = 0; i < 1001; i++) {
	//	road[i].clear();
	//}
	memset(fare, 0, sizeof(fare));
}


void wf(int n) {
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			if (fare[i][j] != 0) {
				for (int k = 0; k < n; k++) {
					if (fare[j][k] != 0) {
						if (fare[i][k] == 0) {
							fare[i][k] = fare[i][j] + fare[j][k];
						}
						else {
							fare[i][k] = min(fare[i][k], fare[i][j] + fare[j][k]);
						}
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("prob-W13/sample-W13_B.1.in", "r", stdin);
	int t, tt = 0;
	cin >> t;
	while (t > tt) {
		int n,m,q;
		cin >> n >> m >> q;
		int u, v,w;
		for (int i = 0; i < m; i++) {
			cin >> u >> v>>w;
			fare[u][v] = w;
			fare[v][u] = w;
		}
		wf(n);
		for (int i = 0; i < q; i++) {
			cin >> u >> v;
			cout << fare[u][v] << "\n";
		}
		reset();
		tt++;
	}

	return 0;
}