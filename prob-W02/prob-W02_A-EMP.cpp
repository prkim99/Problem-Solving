#include<iostream>
#include<vector>
using namespace std;
vector<string> word;
vector <string> wword;

int hamming_distance(string a,string b) {
	int dist=0;
	for (int i = 0; i < a.size();i++) {
		if (a[i] != b[i]) {
			dist++;
		}
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, tt = 0,n,m,val;
	string sentence;
	string v;
	cin >> t;
	while (t>tt) {
		cin >> m >> n;
		for (int i = 0; i < m; i++) {
			cin >> v;
			word.push_back(v);
		}
		cin >> val;
		cin >> sentence;
		for (int i = 0; i < val;) {
			wword.push_back(sentence.substr(i, n));
			i += n;
		}
		for (int i = 0; i < val/n; i++) {
			char rword;
			int distance = n;
			for (int j = 0; j < m; j++) {
				if (distance > hamming_distance(wword[i],word[j])) {
					rword = 65+j;
					distance = hamming_distance(wword[i], word[j]);

				}
			}
			cout << rword;
		}
		cout << endl;
		word.clear();
		wword.clear();
		tt++;
	}

	return 0;
}
