#include <iostream>
#include <algorithm>
#include <vector>
#include<cstring>
#include<set>
#include<iterator>
using namespace std;
vector<int> cal;
multiset<int>dcal;
multiset<int>::iterator it;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, tt = 0;
	cin >> t;
	while (t > tt)
	{
		int n, d, val;
		cin >> n >> d;
		for (int i = 0; i < n; i++) {
			cin >> val;
			cal.push_back(val);
		}
		for (int i = 0; i < d; i++) {
			dcal.insert(cal[i]);
		}
		int chk = 0;
		if (d % 2 == 1) {
			int med = d / 2;
			it = dcal.begin();
			for (int i = 0; i < med; i++) {
				it++;
			}
			for (int i = d; i < n; i++) {
				if ((*it)*2 <= cal[i]) {
					chk++;
				}

				dcal.insert(cal[i]);
				if (*it > cal[i]) {
					it--;
				}
				if (*it >= cal[i - d]) {
					it++;
				}
				dcal.erase(dcal.find(cal[i - d]));
			}
		}
		else {
			int med = d / 2;
			it = dcal.begin();
			for (int i = 0; i < med; i++) {
				it++;
			}

			for (int i = d; i < n; i++) {
				int alert = *it;
				alert += *(--it);
				if (alert<= cal[i]) {
					chk++;
				}
				it++;
				dcal.insert(cal[i]);
				if (*it > cal[i]) {
					it--;
				}
				if (*it >= cal[i - d]) {
					it++;
				}
				dcal.erase(dcal.find(cal[i - d]));
			}
		}
		cout << chk << "\n";
		dcal.clear();
		cal.clear();
		tt++;
	}
	return 0;
}
