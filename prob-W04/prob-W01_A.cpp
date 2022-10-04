
#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<cstdio>
using namespace std;
#include <vector>
#include <algorithm>

vector<int>inha;
vector<int>biry;
vector<int>inha_yak;
vector<int>biry_yak;

int main() {
	
	//freopen("sample-W01_A1.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t, n, m, val;
	
	cin >> t;
	int tt = 0;
	while (tt < t) {
		bool flag_i = true, flag_b = true;
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
		int a = 1;
		while (a*a<fighter) {
			if (fighter % a == 0) {
				biry_yak.push_back(fighter / a);
			}
			a++;
		}
		a = biry_yak.size()-1;
		while (a>=0) {
			biry_yak.push_back(fighter/biry_yak[a]);
			a -- ;
		}
		a = 1;
		while (a * a < fighter_b) {
			if (fighter_b % a == 0) {
				inha_yak.push_back(fighter_b / a);
			}
			a++;
		}
		a = inha_yak.size() - 1;
		while (a >= 0) {
			inha_yak.push_back(fighter_b / inha_yak[a]);
			a--;
		}
		int inha_f = 0;
		int j = fighter;
		biry_yak.push_back(fighter);
		for (int i = 1; i < m;) {
			if (biry[i] % biry_yak[inha_f] != 0) {
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

		for (int i = 0; i < n; i++) {
			if (inha[i] % biry_yak[inha_f] == 0) {
				flag_i = false;
				break;
			}
		}
		for (int i = 0; i < m; i++) {
			if (biry[i] % inha_yak[biry_f] == 0) {
				flag_b = false;
				break;
			}
		}

		if (flag_i && flag_b) {
			cout << biry_yak[inha_f] << " " << inha_yak[biry_f] << "\n";
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