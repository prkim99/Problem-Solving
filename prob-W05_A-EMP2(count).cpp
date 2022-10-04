// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int word[26];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t, tt = 0;
	cin >> t;
	string f, s;
	while (t > tt) {

		bool flag = true;
		cin >> f >> s;
		for (int i = 0; i < f.size(); i++) {
			word[f[i] - 'A']=1;
		}
		for (int i = 0; i < s.size(); i++) {
			if (word[s[i] - 'A'] == 0) {
				flag = false;
			}
			else {
				word[s[i] - 'A']++;
			}
		}
		for (int i = 0; i < 26; i++) {
			if (word[i] == 1) {
				flag = false;
			}
		}

		if (flag) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
		memset(word, 0, sizeof(word));
		tt++;
	}


	return 0;
}

