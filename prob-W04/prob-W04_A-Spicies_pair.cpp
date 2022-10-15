//#include<iostream>
//#include <vector>
//#include<algorithm>
//using namespace std;
//vector<pair<int, int>> sp;
//vector<int> w;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	int t, tt = 0;
//	cin >> t;
//	while (t > tt) {
//		int n, k,val;
//		cin >> n >> k;
//		for (int i = 0; i < n; i++) {
//			cin >> val;
//			w.push_back(val);
//		}
//		for (int i = 0; i < n; i++) {
//			cin >> val;
//			sp.push_back({ val / w[i],w[i]});
//		}
//		sort(sp.begin(), sp.end(), greater<>());
//		int f=0;
//		int i = 0;
//		int money=0;
//		while (f < k&&i<sp.size()) {
//			if ((k - f) >= sp[i].second) {
//				money += sp[i].first * sp[i].second;
//				f += sp[i].second;
//			}
//			else {
//				money += (k - f) * sp[i].first;
//				f += k - f;
//			}
//			i++;
//		}
//		w.clear();
//		sp.clear();
//		cout << money << "\n";
//		tt++;
//	}
//
//	return 0;
//}