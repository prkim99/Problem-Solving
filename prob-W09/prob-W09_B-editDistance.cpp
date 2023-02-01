#include <iostream>
#include <string>
#include <algorithm>
#include<cstring>
using namespace std;

int dist[1001][1001];

int levenshtein(string x_str, string y_str) {
    for (int i = 0; i <= x_str.size(); i++)
        dist[0][i] = i;
    for (int i = 0; i <= y_str.size(); i++)
        dist[i][0] = i;

    for (int  x= 1; x <= x_str.length(); x++) {
        for (int y = 1; y <= y_str.length(); y++) {

            if (x_str[x - 1] == y_str[y - 1]) {
                dist[y][x] = dist[y - 1][x - 1];
            }
            else {
                dist[y][x] = min(dist[y - 1][x - 1], min(dist[y - 1][x], dist[y][x - 1])) + 1;

            }

        }
    }

    return dist[y_str.length()][x_str.length()];
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, tt = 0;
    cin >> t;
    while (t > tt) {

        string x, y;
        cin >> y >> x;
        
        cout << levenshtein(x, y) << "\n";
        memset(dist, 0, sizeof(dist));
        tt++;
    }

    return 0;
}
