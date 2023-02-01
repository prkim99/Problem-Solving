//// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
////
//
//#include<vector>
//#include<iostream>
//#include<algorithm>
//#include<queue>
//#include<cstring>
//using namespace std;
//queue<int> al[59];
//queue<int> all[59];
//int dp[50];
//
//int main()
//{
//    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//    int t, tt = 0;
//    cin >> t;
//    while (t > tt) {
//
//        string x,y;
//        int msum = 10000;
//        int msum1 = 10000;
//        cin >> y >> x;
//        for (int i = 0; i < x.size(); i++) {
//            al[x[i] - 'A'].push(i);
//        }
//        int sum = 0;
//
//        for (int k = 0; k < y.size(); k++) {
//            int dif_s = 0;
//            int sump = k;
//            sum = 0;
//            for (int i = k; i < y.size(); i++){
//              
//                while (!al[y[i] - 'A'].empty()) {
//                    if ((al[y[i] - 'A'].front() - dif_s) < 0) {
//                        al[y[i] - 'A'].pop();
//                    }
//                    else {
//                        break;
//                    }
//                }
//                
//                // abdc(+4) sssdg sesdh
//
//                if (!al[y[i] - 'A'].empty()) {
//                    if()
//                    if (sump > al[y[i] - 'A'].front() - dif_s) {
//                        sum += sump;
//                    }
//                    else {
//                        sum += al[y[i] - 'A'].front() - dif_s;
//                    }
//                    dif_s = al[y[i] - 'A'].front() + 1;
//                    al[y[i] - 'A'].pop();
//                    sump = 0;
//;
//                }
//                else {
//                    sump++;
//                }
//            }
//            if (sump > x.size() - dif_s) {
//                sum += sump;
//            }
//            else {
//                sum += x.size() - dif_s;
//            }
//            if (msum > sum) {
//                msum = sum;
//            }
//            for (int q = 0; q < x.size(); q++) {
//                while (!al[x[q]-'A'].empty()) {
//                    al[x[q] - 'A'].pop();
//                }
//            }
//            for (int q = 0; q < x.size(); q++) {
//                al[x[q] - 'A'].push(q);
//            }
//        }
//
//        cout << msum << "\n";
//        for (int q = 0; q < x.size(); q++) {
//            while (!al[x[q] - 'A'].empty()) {
//                al[x[q] - 'A'].pop();
//            }
//        }
//        tt++;
//    }
//
//    return 0;
//}