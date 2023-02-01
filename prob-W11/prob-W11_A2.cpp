#define _crt_secure_no_warnings
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
vector<pair<int, int>> cnt;

void reset() {
	cnt.clear();
//	inhateam.clear();
//	play.clear();
//	chk.clear();
//	//while (!pq.empty()) {
//	//	pq.pop();
//	//}
	//for (int i = 0; i < 1001; i++) {
	//	road[i].clear();
	//}
	//memset(fare, 0, sizeof(fare));
}

int cal2(int n) {
	int k = 0;
	while (n > 1) {
		n=n >> 1;
		k++;
	}
	return k;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("prob-w13/sample-w13_b.1.in", "r", stdin);
	int t, tt = 0;
	cin >> t;
	cnt.push_back({ 1,2 });
	while (t > tt) {
		int n;
		cin >> n;
		int k=cal2(n);
		
		int l = cnt.size() + 1;
		while(k>=cnt.size()) {
			
			int f2 = 1;
			for (int i = 0; i < l -2; i++) {
				f2 *= 2;
			}
			int new_zero = (l - 1) * f2+1+cnt[cnt.size() - 1].first;
			int one = new_zero - cnt[cnt.size() - 1].first;
			cnt[cnt.size() - 1].second = one;
			cnt.push_back({ new_zero,0 });
			l++;
		}
		cout << cnt[k-1].first << " " << cnt[k-1].second << "\n";
		tt++;
	}

	return 0;
}