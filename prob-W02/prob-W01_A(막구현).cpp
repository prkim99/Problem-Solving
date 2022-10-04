#include<iostream>
using namespace std;
#include <vector>
#include<algorithm>

vector<int>inha;
vector<int>biry;
vector<int>inha_yak;
vector<int>biry_yak;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t, n, m, val;
	bool flag_i = false, flag_b = false;
	cin >> t;
	int tt = 0;
	while (tt < t) {
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

		int fighter = biry[0];

		int fighter_b = inha[0];


		int inha_f = 0;
		int j = fighter;
		biry_yak.push_back(fighter);
		for (int i = 1; i < m;) {
			if (biry[i] % biry_yak[inha_f] != 0) {
				while (j > 2) {
					j--;
					if (fighter % j == 0) {
						biry_yak.push_back(j);
						break;
					}
				}
				inha_f++;
				flag_i = false;
			}
			else {
				i++;
				flag_i = true;
			}
			if (inha_f == biry_yak.size()) {
				break;
			}
		}
		int biry_f = 0;
		j = fighter_b;
		inha_yak.push_back(fighter_b);
		for (int i = 1; i < n;) {
			if (inha[i] % inha_yak[biry_f] != 0) {
				while (j > 2) {
					j--;
					if (fighter_b % j == 0) {
						inha_yak.push_back(j);
						break;
					}
				}
				biry_f++;
				flag_b = false;
			}
			else {
				i++;
				flag_b = true;
			}
			if (biry_f == inha_yak.size()) {
				break;
			}
		}
		if (flag_i && flag_b) {
			if (biry_yak[inha_f] % inha_yak[biry_f] == 0) {
				cout << biry_yak[inha_f] << " " << -1 << "\n";
			}
			else if (inha_yak[biry_f] % biry_yak[inha_f] == 0) {
				cout << -1 << " " << inha_yak[biry_f] << "\n";
			}
			else if (inha_yak[biry_f] == biry_yak[inha_f]) {
				cout << -1 << " " << -1 << endl;
			}
			else {
				cout << biry_yak[inha_f] << " " << inha_yak[biry_f] << "\n";
			}
		}
		else if (flag_i) {
			cout << biry_yak[inha_f] << " " << -1 << "\n";
		}
		else if (flag_b) {
			cout << -1 << " " << inha_yak[biry_f] << "\n";
		}
		else {
			cout << -1 << " " << -1 << endl;
		}
		tt++;
		inha.clear();
		biry.clear();
		inha_yak.clear();
		biry_yak.clear();
	}
	return 0;
}