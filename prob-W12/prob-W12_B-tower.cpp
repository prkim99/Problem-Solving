#include <iostream>
#include<set>
#include<algorithm>
using namespace std;
set<pair<int, int>> s;
set<pair<int, int>>::iterator it;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t, tt = 0;
	cin >> t;
	while (t > tt) {
		int n,p;
		cin >> n;
		s.insert({ 0,-1 });
		for (int i = 0; i < n; i++) {
			cin >> p;
			s.insert({ p,i + 1 });
			it = s.lower_bound({ p,i + 1 });
			cout << (*(--it)).second << " ";
		}
		cout << "\n";
		s.clear();
		tt++;
	}

	return 0;
}
