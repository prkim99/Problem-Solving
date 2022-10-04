
#include <iostream>
#include<string>
using namespace std;

int main() {
	//freopen("sample-W03_B.1.in", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, tt = 0;
	long long int m;
	cin >> t;
	while (t > tt) {
		cin >> m;
		int days=0;
		while (m > 0) {
			int num = m % 10;
			if (num>5) {
				days += 10 - num;
				m += 10;
			}
			else if (num<5) {
				days += num;
			}
			else {
				days += 5;
				if (m % 100/10 >= 5) {
					m += 10 ;
				}
			}
			m /= 10;
		}
		cout << days << "\n";

		tt++;
	}

	return 0;
}