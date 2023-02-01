// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
vector<int> a;
vector<int> c[362880];
vector<long long int> xsq;

int cal_permutation() {
	int k = 0;
	do {
		for (int i = 0; i < a.size(); i++)
		{
			c[k].push_back(a[i]);
		}
		k++;
	} while (next_permutation(a.begin(), a.end()));

	return k;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t,tt = 0;
	cin >> t;
	while (t > tt) {
		int n, p, q,val,x;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> val;
			a.push_back(val);
		}
		cin >> p >> q;
		cin >> x;
		long long int tmp = 1;
		xsq.push_back(1);
		for (int i = 1; i < n; i++) {
			tmp *= x;
			xsq.push_back(tmp);
		}
		sort(a.begin(), a.end());
		int cases = cal_permutation();
		int cnt = 0;
		for (int i = 0; i < cases; i++) {
			long long int result=0;
			for (int j = 0; j < xsq.size(); j++) {
				result += c[i][j] * xsq[j];
			}
			//cout << result<<" ";
			result = result % 1013;
			//cout << result<<endl;
			if (result >= p && result <= q) {
				cnt++;
			}
		}
		cout << cnt << "\n";

		a.clear();
		xsq.clear();
		for (int i = 0; i < cases; i++) {
			c[i].clear();
		}
		tt++;
	}
}



void Permutation(vector<int>& Array, int s_index, int e_index)
{
	if (s_index == e_index)
	{
		for (int i = 0; i < Array.size(); i++)
		{
			cout << Array[i] << " ";
		}
		cout << "\n";
	}
	else
	{
		for (int i = s_index; i <= e_index; ++i)
		{
			swap(Array[s_index], Array[i]);
			Permutation(Array, s_index + 1, e_index);
			swap(Array[s_index], Array[i]);
		}
	}
}


// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
