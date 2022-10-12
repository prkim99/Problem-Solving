
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;

vector<pair<int, int>> dist[50000];
vector<pair<int, int>> visit;
string loc[50000];
map<string, int > num;
int visity[50000];
stack<int> st;
int ttt, tt = 0, n, m, year, spend;
bool visited[50000];

int calTime(int start) {
	int totalt[50000];
	totalt[start] = 0;
	st.push(start);
	int node;
	int max = 0;
	while (st.size() > 0) {
		node = st.top();
		st.pop();
		visited[node] = true;
		for (int i = 0; i < dist[node].size(); i++) {
			int snode = dist[node][i].second;
			if (visity[node] < visity[snode]) {
				totalt[snode] = totalt[node] + dist[node][i].first;
				st.push(snode);
				if (totalt[snode] > max) {
					max = totalt[snode];
				}
			}
		}
	}
	return max;
}
int calTime_les(int start) {
	int totalt[50000];
	totalt[start] = 0;
	st.push(start);
	int node;
	int max = 0;
	while (st.size() > 0) {
		node = st.top();
		st.pop();
		visited[node] = true;
		for (int i = 0; i < dist[node].size(); i++) {
			int snode = dist[node][i].second;
			if (visity[node] > visity[snode]) {
				totalt[snode] = totalt[node] + dist[node][i].first;
				st.push(snode);
				if (totalt[snode] > max) {
					max = totalt[snode];
				}
			}
		}
	}
	return max;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	cin >> ttt;
	string f, t, site;
	while (ttt > tt) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> f >> year;
			num[f] = i;
			loc[i] = f;
			visity[i] = year;
			visit.push_back({ year, i });
		}
		for (int i = 0; i < m; i++) {
			cin >> f >> t >> spend;
			dist[num[f]].push_back({ spend,num[t] });
			dist[num[t]].push_back({ spend,num[f] });
		}
		sort(visit.begin(), visit.end());
		int max = 0;
		for (int i = 0; i < n; i++) {
			if (visited[visit[i].second] == false) {
				int value = calTime(visit[i].second)+calTime_les(visit[i].second);
				if (max < value)
					max = value;
			}
		}
		cout << max << "\n";
		for (int i = 0; i < n; i++) {
			dist[i].clear();
		}
		visit.clear();
		num.clear();
		memset(visity, 0, sizeof(visity));
		memset(visited, 0, sizeof(visited));
		tt++;
	}


	return 0;
}

