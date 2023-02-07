// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

vector<pair<int, int>> shark;
vector<int> cage;
priority_queue<pair<int, int>,vector<pair<int, int>>,greater<>> heap;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t, tt = 0;
	cin >> t;
	while (t > tt) {
		int n, m,a,b,val;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			shark.push_back({ a,b });
		}
		sort(shark.begin(), shark.end());
		for (int i = 0; i < m; i++) {
			cin >> val;
			cage.push_back(val);
		}
		sort(cage.begin(), cage.end());
		int cnt = 0;
		int j = 0;
		for (int i = 0; i < m; i++) {
			while (j < n&&shark[j].first <= cage[i] ) {
				heap.push({ shark[j].second,shark[j].first });
				j++;
			}
			while (!heap.empty()&&heap.top().first < cage[i]) {
				heap.pop();
			}
			if (!heap.empty()) {
				heap.pop();
				cnt++;
			}

		}


		cout << cnt << "\n";
		cage.clear();
		shark.clear();
		while (!heap.empty()) {
			heap.pop();
		}
		tt++;
	}
}
