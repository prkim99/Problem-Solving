// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
vector<pair<int,int>> height;
vector<int> road[1001];
int money[1001];

void BFS(int head) {
    int node = head;
    queue<int> q;
    q.push(node);
    while (!q.empty()) {
        node = q.front();
        q.pop();
        for (int i = 0; i < road[node].size(); i++) {
            int cnode = road[node][i];
            if (money[cnode] == 0&&cnode!=head) {
                money[cnode] = money[node] + 1;
                q.push(cnode);
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, tt = 0;
    cin >> t;
    while (t > tt) {
        int n, m, k,val;
        cin >> n >> m >> k;
        for (int i = 0; i < n; i++) {
            cin >> val;
            height.push_back({ val,i });
        }
        sort(height.begin(),height.end());
        int head = height[0].second;
        int i, j;
        for (int l = 0; l < m; l++) {
            cin >> i>>j;
            road[i].push_back(j);
            road[j].push_back(i);
        }

        BFS(head);

        for (int i = 0; i < k; i++) {
            cin >> val;
            if (val == head) {
                cout << 0 << "\n";
            }
            else if (money[val] == 0) {
                cout << -1 << "\n";
            }
            else {
                cout << money[val] << "\n";
            }
        }
        for (int i = 0; i <= n; i++) {
            road[i].clear();
        }
        height.clear();
        memset(money, 0, sizeof(money));

        tt++;
    }

    return 0;
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
