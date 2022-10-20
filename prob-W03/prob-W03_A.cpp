#include <iostream>
#include <algorithm>
#include <vector>
#include<cstring>

using namespace std;
vector<int> cal;
int dcal[201];

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
			dcal[cal[i]]++;
		}
		int chk = 0;
		int alert;
		for (int i = d; i < n; i++) {
			if (d % 2 == 1) {
				int med = d / 2 + 1;
				int val = 0;
				int sum = 0;
				for (int j = 0; j <= 200; j++) {
					sum += dcal[j];
					if (sum >= med) {
						val = j;
						break;
					}
				}
				alert = 2 * val;
			}
			else {
				int med = d / 2;
				int val = 0;
				int val2 = 0;
				int sum = 0;
				for (int j = 0; j <= 200; j++) {
					sum += dcal[j];
					if (sum >= med&&val==0) {
						val = j;
					}
					if (sum >= (med + 1)) {
						val2 = j;
						break;
					}

				}
				alert = (val + val2);
			}
			if (alert <= cal[i]) {
				chk++;
			}
			dcal[cal[i]]++;
			dcal[cal[i - d]]--;
		}
		cout << chk << "\n";
		memset(dcal, 0, sizeof(dcal));
		cal.clear();
		tt++;
	}
	return 0;
}