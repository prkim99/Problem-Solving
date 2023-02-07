//// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
////
//
//#include <iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//using namespace std;
//vector <pair<long long int, long long int>> tmp;
//
//
//int cal2(int a) {
//	int k = 0;
//	while (a > 1) {
//		a = a >> 1;
//		k++;
//	}
//	return k;
//}
//long long int calC(int n, int k) {
//	long long int result = 1;
//	int l = k;
//	if ((n - k) < k) {
//		l = n - k;
//	}
//	int j = 1;
//	for (int i = n; i >= n - l + 1; i--, j++) {
//		result *= i;
//		result /= j;
//	}
//	return k * result;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int t, tt = 0;
//	cin >> t;
//
//	tmp.push_back({ 1,2 });
//	while (t > tt) {
//		int n;
//		cin >> n;
//		int sq= cal2(n);
//		if (sq < tmp.size()) {
//			cout << tmp[sq - 1].first << " " << tmp[sq - 1].second << "\n";
//
//		}
//		else {
//			for (int ll = tmp.size(); ll <= sq; ll++) {
//				long long int count = tmp[ll-1].first;
//				for (int i = 1; i < ll; i++) {
//					count += calC(ll, i);
//				}
//				count += ll + 1;
//				tmp.push_back({ count,0 });
//				tmp[ll - 1].second = count - tmp[ll - 1].first;
//			}
//			cout << tmp[sq - 1].first << " " << tmp[sq - 1].second << "\n";
//		}
//		tt++;
//	}
// 
//
//	return 0;
//}
//
//// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
//// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴
//
//// 시작을 위한 팁: 
////   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
////   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
////   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
////   4. [오류 목록] 창을 사용하여 오류를 봅니다.
////   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
////   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
