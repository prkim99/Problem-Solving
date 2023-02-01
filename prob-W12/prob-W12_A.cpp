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

//void reset() {
//	r.clear();
//	inhateam.clear();
//	play.clear();
//	chk.clear();
//	//while (!pq.empty()) {
//	//	pq.pop();
//	//}
//	/*for (int i = 0; i < k; i++) {
//		aa[i].clear();
//	}*/
//	memset(score, 0, sizeof(score));
//}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("prob-W12/sample-W12_A.1.in", "r", stdin);
	int t, tt = 0;
	cin >> t;
	
	while (t > tt) {
		int x, a, b;
		cin >> x >> a >> b;
		int bi = x;
		int to = 0;
		int k = 0;
		while (to<bi) {
			bi += a;
			to += 2*a;
			if (to >= bi) {
				break;
			}
			bi += b;
		}
		bi -= a;
		to -= 2 * a;

		while (to < bi) {
			bi += 1;
			to += 2;
		}
		cout << bi << "\n";
		//reset();
		tt++;
	}

	return 0;
}