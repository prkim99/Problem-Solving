#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include<iterator>
#include<set>

using namespace std;
vector<int> cal;
multiset<int> dcal;
multiset<int>::iterator it;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, tt = 0;
	cin >> t;
	while (t>tt)
	{
		int n, d,val;
		cin >> n >> d;
		for (int i = 0; i < n; i++) {
			cin >> val;
			cal.push_back(val);
		}
		for (int i = 0; i < d; i++) {
			dcal.insert(cal[i]);
		}
		int alert = 0;
		if (d % 2 == 1) {
			int med = d / 2 + 1;
			it = dcal.begin();
			for (int i = 0; i < med; i++) {
				it++;
			}
			for (int i = d; i < n; i++) {
				if (cal[i] >= (*it * 2)) {
					alert++;
				}
				it
			}
		}
		else {

		}

		

		tt++;
	}
	return 0;
}