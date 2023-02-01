////12주차 B.마법의탑
////correct!
////저거 시간줄이는 ㅓㄱ 꼭 넣어야함 
//#include<iostream>
//#include<set>
//using namespace std; 
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	int t; 
//	cin >> t; 
//	while (t--) {
//		int n; 
//		cin >> n; 
//		set<pair<int, int>> s; 
//		s.insert(make_pair(0, -1)); //0층에 -1능력치 저장
//		int level;
//		for (int i = 0; i < n; i++) {
//			cin >> level;
//			pair<int, int> p = make_pair(level, i + 1);
//			s.insert(p);
//			set<pair<int, int>>::iterator iter = s.find(make_pair(level, i + 1));
//			iter--;
//			int r = (*iter).second;
//			cout << r << " ";
//		}
//		cout << endl;
//		s.clear();
//	}
//}
//
