#include<iostream>
using namespace std;
#include <stack>

stack<int> carrot;
stack<int> throne;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, tt = 0;
	cin >> t;
	while (t > tt) {
		string sen;
		cin >> sen;
		int size = 0;
		int msize=0,mmsize=0;
		for (int i = 0; i < sen.size(); i++) {
			if (sen[i] == 'C') {
				carrot.push(i);
			}
			else {
				if (!carrot.empty()) {
					if (carrot.size() == 1) {
						size += i - carrot.top() + 1;
					}
					if (msize < size) {
						msize = size;
					}
					carrot.pop();
				}
				else {
					size = 0;
				}
			}
		}
		size = 0;
		for (int i = sen.size()-1; i >=0; i--) {
			if (sen[i] == 'T') {
				throne.push(i);
			}
			else {
				if (!throne.empty()) {
					if (throne.size() == 1) {
						size += throne.top()-i + 1;
					}
					if (mmsize < size) {
						mmsize = size;
					}
					throne.pop();
				}
				else {
					size = 0;
				}
			}
		}
		if (mmsize > msize) {
			msize = mmsize;
		}
		while (!carrot.empty()) {
			carrot.pop();
		}
		while (!throne.empty()) {
			throne.pop();
		}
		cout << msize << "\n";
		tt ++ ;
	}
	return 0;
}