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
		int k=cal2(n);//2의 몇승인지 확인
		
		//k=4(10000)이고 cnt.size()가 3일때
		//cnt 크기가 3이라는 거는 {1,2}, {3,5}, {8,0} 이렇게 들어있다는 걸 뜻함
		while(k>=cnt.size()) {
			long long int count = 0;
			int l = cnt.size();
			//(즉 k가 cnt.size -1 보다 작을때 까지의 0의 자리수 합과 1의 자리수 합이 저장되어있음)
			for (int i = 1; i < l; i++) {
				count += calCom(l, i); 
				//이건 n=2^4일때 1001~1111까지 3개의 자리중에 0이 1개들어갈때, 두개들어갈때 세는 방법 쓴거얌!
				//예를 들어 3C1*1+3C2*2 이거 더하는 함수
			}
			//count=3+6=9


			int new_zero = count+cnt[cnt.size() - 1].first+ㅣ+1;
			//10000일때 0 네개 들어가는거 더해줌 
			//10000까지의 0개수 합= 9 +(1000까지의 0 개수 합)+ 4(=3+1)=9+8+4=21

			int one = new_zero - cnt[cnt.size() - 1].first;
			//1000까지의 1의 개수= 10000까지의 0의개수 합-1000까지의 0의 개수
			//21-8=13

			cnt[cnt.size() - 1].second = one;
			//1000까지의 1의 개수 초기화
			//cnt={1,2}, {3,5}, {8,13},

			cnt.push_back({ new_zero,0 });
			//10000까지의 0의 개수 삽입
			//cnt={1,2}, {3,5}, {8,13}, {21,0}
		}
		cout << cnt[k-1].first << " " << cnt[k-1].second << "\n";
		tt++;
	}

	return 0;
}