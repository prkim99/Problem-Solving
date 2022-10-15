#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
vector<pair<int,int>> rode[50001];
map<string,int> name;
int year[50001];
int n, m,val;
string sen,sen1;
vector<int> s;
bool visit[50001];
vector<pair<int,int>> v;

void tpsort(int start) {
	int node = start;
	queue<int> q;
	q.push(node);
	visit[node] = true;
	while (!q.empty()) {
		node = q.front();
		q.pop();
		for (int i = 0; i < rode[node].size(); i++) {
			int cnode = rode[node][i].first;
			int range = rode[node][i].second;
			if (visit[cnode] == false || s[cnode] < s[node] + range) {
				visit[cnode] = true;
				s[cnode] = s[node] + range;
				q.push(cnode);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, tt = 0;
	cin >> t;
	while (t > tt) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> sen>>val;
			name[sen] = i;
			year[i] = val;
			s.push_back(0);
			v.push_back({ val, i });
			//v.push_back()
		}
		int ii, iii;
		for (int i = 0; i < m; i++) {
			cin >> sen >>sen1>> val;
			ii = name[sen];
			iii = name[sen1];
			if (year[ii] > year[iii]) {
				rode[iii].push_back({ ii,val });
			}
			else if(year[ii] < year[iii]) {
				rode[ii].push_back({ iii,val });
			}
		}
		sort(v.begin(), v.end());
		for (int i =0; i < n;i++) {
			if (visit[v[i].second] == false) {
				tpsort(v[i].second);
			}
		}
		sort(s.begin(), s.end(),greater<>());
		cout << s[0] << "\n";
		s.clear();
		v.clear();
		tt++;
		for (int i = 0; i <= n; i++) {
			rode[i].clear();
		}
		memset(year, 0, sizeof(year));
		memset(visit, false, sizeof(visit));
		name.clear();
	}
	return 0;
}