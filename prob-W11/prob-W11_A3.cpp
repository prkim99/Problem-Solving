#define _crt_secure_no_warnings
#include <iostream>
#include<set>
#include<algorithm>
#include<stack>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;
vector<pair<long long int, long long int>> cnt;

void reset() {
	cnt.clear();
//	inhateam.clear();
//	play.clear();
//	chk.clear();
//	//while (!pq.empty()) {
//	//	pq.pop();
//	//}
	//for (int i = 0; i < 1001; i++) {
	//	road[i].clear();
	//}
	//memset(fare, 0, sizeof(fare));
}

int cal2(int n) {
	int k = 0;
	while (n > 1) {
		n=n >> 1;
		k++;
	}
	return k;
}
long long int calCom(int n, int r) {
	int k = r;
	if (n - r < r) {
		k = n - r;
	}
	long long int result = 1;
	for (int i = n, j = 1; j <= k; i--, j++) {
		result *= i;
		result /= j;
	}
	return r * result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("prob-w13/sample-w13_b.1.in", "r", stdin);
	int t, tt = 0;
	cin >> t;
	cnt.push_back({ 1,2 });
	while (t > tt) {
		int n;
		cin >> n;
		int k=cal2(n);//2�� ������� Ȯ��
		
		//k=4(10000)�̰� cnt.size()�� 3�϶�
		//cnt ũ�Ⱑ 3�̶�� �Ŵ� {1,2}, {3,5}, {8,0} �̷��� ����ִٴ� �� ����
		while(k>=cnt.size()) {
			long long int count = 0;
			int l = cnt.size();
			//(�� k�� cnt.size -1 ���� ������ ������ 0�� �ڸ��� �հ� 1�� �ڸ��� ���� ����Ǿ�����)
			for (int i = 1; i < l; i++) {
				count += calCom(l, i); 
				//�̰� n=2^4�϶� 1001~1111���� 3���� �ڸ��߿� 0�� 1������, �ΰ����� ���� ��� ���ž�!
				//���� ��� 3C1*1+3C2*2 �̰� ���ϴ� �Լ�
			}
			//count=3+6=9


			int new_zero = count+cnt[cnt.size() - 1].first+��+1;
			//10000�϶� 0 �װ� ���°� ������ 
			//10000������ 0���� ��= 9 +(1000������ 0 ���� ��)+ 4(=3+1)=9+8+4=21

			int one = new_zero - cnt[cnt.size() - 1].first;
			//1000������ 1�� ����= 10000������ 0�ǰ��� ��-1000������ 0�� ����
			//21-8=13

			cnt[cnt.size() - 1].second = one;
			//1000������ 1�� ���� �ʱ�ȭ
			//cnt={1,2}, {3,5}, {8,13},

			cnt.push_back({ new_zero,0 });
			//10000������ 0�� ���� ����
			//cnt={1,2}, {3,5}, {8,13}, {21,0}
		}
		cout << cnt[k-1].first << " " << cnt[k-1].second << "\n";
		tt++;
	}

	return 0;
}