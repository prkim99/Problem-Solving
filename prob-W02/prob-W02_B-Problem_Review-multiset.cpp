#include<iostream>
#include<set>
using namespace std;
multiset <int> level;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, tt = 0, m, n, val;
	string oper;
	cin >> t;
	while (t>tt) {
		cin >> m >> n;
		for (int i = 0; i < m; i++) {
			cin >> val;
			level.insert(val);
		}
		for (int i = 0; i < n; i++) {
			cin >> oper;
			if (oper == "Add") {
				cin >> val;
				level.insert(val);
			}
			else {
				cin >> oper;
				if (oper == "min") {
					level.erase(level.begin());
				}
				else {
					level.erase(--level.end());
				}
			}

		}
		cout <<*level.begin() <<" "<<*level.rbegin() << endl;
		level.clear();
		tt++;
	}

	return 0;
}
