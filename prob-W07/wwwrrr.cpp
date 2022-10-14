#include<iostream>
#include<cstring>
using namespace std;
int val[10000];

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
		int p1, p2,m=0,w=0;
		p1 = 0, p2 = 1;
		int max_len = 0;
		bool flag = false;
		
		for (int i = 0; i < len; i++) {
			val[i] = sen[i] - '0';
			if (val[i] == 1) {
				w++;
			}
			else {
				m++;
				val[i]--;
			}
		}
		if (w > m) {
			w = m;
			for (int i = 0; i < len; i++) {
				if (val[i] == 1) {
					val[i] = -1;
				}
				else {
					val[i] = 1;
				}
			}
		}

		int sum = val[p1]+val[p2];
		if (sum == 0)
			max_len = 2;
		if (val[p1] == 1)
			w--;
		if (val[p2] == 1) {
			w--;
		}
		//여자 5명 끝나면
		if ((sum + w) < 0) {
			flag = true;
		}
		while(p2<len&&p1<p2){
			if (p1 == 0 && p2 == 1)
				continue;
			if (flag) {
				p1++;
				sum -= val[p1-1];
				
				if (sum+w>=0) {
					flag = false;					
				}
			}
			else {
				p2++;
				sum += val[p2];
				//여자 개수 세기
				if (val[p2] == 1) {
					w--;
				}
				//여자 5명 끝나면
				if ((sum+w)<0) {
					flag = true;
				}
			}
		if (sum == 0) {
			if (max_len < p2 - p1 + 1) {
				max_len = p2 - p1 + 1;
				}
			}
		}
		cout << max_len << "\n";
		memset(val, 0, sizeof(val));
		tt++;
	}

	return 0;
}