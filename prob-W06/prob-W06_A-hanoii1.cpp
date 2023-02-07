#include <iostream>
#include <stack>
#include<iterator>
using namespace std;
stack<int> s[3];
int n,k;
int cnt=0;

bool hanoii(int n,int from, int via,int to){
	
	if (n == 0) {
		return false;
	}
	
	if (hanoii(n - 1, from, to, via)) {
		return true;
	}

	s[from].pop();
	s[to].push(n);

	if (++cnt == k) {
		return true;
	}

	hanoii(n - 1, via, from, to);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,tt=0;
	cin>>t;
	while (t > tt) {
		cnt = 0;
		cin >> n;
		cin >> k;
		for (int i = n; i >= 1; i--) {
			s[0].push(i);
		}
		hanoii(n, 0, 1, 2);
		if(!s[1].empty()) {
			while (!s[1].empty()) {
				cout << s[1].top() << " ";
				s[1].pop();
			}
			cout << "\n";
		}
		else {
			cout << 0 << "\n";
		}
		while (!s[0].empty()) {
			s[0].pop();
		}
		while (!s[2].empty()) {
			s[2].pop();
		}
		tt++;
	}
	return 0;
}
