#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> inha;
vector<int> biry;
int gcd(int a,int b) {
	int v;
	while (b != 0) {
		v = a % b;
		a = b;
		b = v;
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, tt = 0;
	cin >> t;
	while (t > tt) {
		int n, m,val,inha_f,biry_f;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> val;
			inha.push_back(val);
		}
		for (int i = 0; i < m; i++) {
			cin >> val;
			biry.push_back(val);
		}
		sort(inha.begin(), inha.end());
		sort(biry.begin(), biry.end());
		biry_f = inha[0];
		for (int i = 1; i < n; i++) {
			biry_f = gcd(biry_f, inha[i]);
		}
		inha_f = biry[0];
		for (int i = 1; i < m; i++) {
			inha_f = gcd(inha_f, biry[i]);
		}
		for (int i = 0; i < n; i++) {
			if ((inha[i] % inha_f) == 0) {
				inha_f = -1;
				break;
			}
		}
		for (int i = 0; i < m; i++) {
			if ((biry[i] % biry_f) == 0) {
				biry_f = -1;
				break;
			}
		}
		cout << inha_f << " " << biry_f << "\n";
		biry.clear();
		inha.clear();
		tt++;
	}
	return 0;
}