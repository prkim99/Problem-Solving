////12���� B.������ž
////correct!
////���� �ð����̴� �ä� �� �־���� 
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
//		s.insert(make_pair(0, -1)); //0���� -1�ɷ�ġ ����
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
