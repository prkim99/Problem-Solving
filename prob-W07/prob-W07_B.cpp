#include<iostream>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
vector<int> acSum;
map<int, int> seq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, tt = 0;
	cin >> t;
	string sen;
	while (t > tt) {
		cin >> sen;
		int len = sen.length();
		int max_len = 0;
		int val;
		acSum.push_back(0);
		seq[0] = 0;
		for (int i = 0; i < len; i++) {
			val = sen[i] - '0';
			if (val == 1) {
				acSum.push_back(acSum[i] + 1);
			}
			else {
				acSum.push_back(acSum[i] - 1);
			}
			if (seq.count(acSum[i+1]) == 0) {
				seq[acSum[i+1]] = i+1;
			}
			else {
				if (max_len < i - seq[acSum[i+1]]+1) {
					max_len = i - seq[acSum[i+1]]+1 ;
				}
			}
		}

		cout << max_len << "\n";
		seq.clear();
		acSum.clear();
		tt++;
	}

	return 0;
}