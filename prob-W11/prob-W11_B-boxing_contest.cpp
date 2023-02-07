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
using namespace std;
vector<int> r;
int score[100001];
vector<int> inhateam;
vector<pair<int,int>> play;
vector<int> chk;

void reset() {
	r.clear();
	inhateam.clear();
	play.clear();
	chk.clear();
	//while (!pq.empty()) {
	//	pq.pop();
	//}
	/*for (int i = 0; i < k; i++) {
		aa[i].clear();
	}*/
	memset(score, 0, sizeof(score));
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("prob-W11/sample-W11_B.1.in", "r", stdin);
	int t, tt = 0;
	cin >> t;
	
	while (t > tt) {
		int n, m, a,b,val,win=1;
		cin >> n >> m;
		r.push_back(0);
		for (int i = 1; i <=n ; i++) {
			cin >> val;
			r.push_back(val);
			score[val] += n-i+1;
			if (val == 1) {
				inhateam.push_back(i);
			}
		}//n

		for (int i = 2; i <= m; i++) {
			if (score[1] <= score[i]) {
				chk.push_back(i);
			}
		}//인하팀보다 점수가 같거나 높은 팀 최대힙에 넣음 mlogm
		
		if (chk.empty()) {
			cout << 0 << "\n";
		}//이미 인하팀이 일등일때
		else{
			int cnt = 0;
			bool flag = false;
			for (int i = 1; i < inhateam.size(); i++) {
				if (r[inhateam[i] - 1] == 1) {
					continue;
				}
				play.push_back({ score[r[inhateam[i] - 1]], inhateam[i]});
				//{인하팀 멤버가 경기할 상대팀의 현재 점수, 인하팀 멤버} 이렇게 담아서
			}//n
			sort(play.begin(), play.end(), greater<>()); //mlogm
			//현재 점수가 높은 팀부터 경기를 진행함(최대한 1등에 가까운 팀의 점부부터 까는게 중요하므로!)
			
			int chk_count = 0;
			for (int i = 0; i <play.size(); i++) {
				score[r[play[i].second - 1]]--;
				score[1]++;
				cnt++;
				while (chk_count<chk.size() && score[1] > score[chk[chk_count]]) {
					chk_count++;
				}//인하팀보다 더 높은 점수 였던 사람하나씩 지움
				if (chk_count==chk.size()) {
					break;
				}
			}//n+m

			if (chk_count == chk.size()) {
				cout << cnt << "\n";
			}
			else {
				cout << -1 << "\n";
			}
		}

		reset();
		tt++;
	}

	return 0;
}
