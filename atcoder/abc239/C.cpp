#include <bits/stdc++.h>

using namespace std;

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    set<pair<int, int>> nxt1, nxt2;
    for(int i = 0; i < 8; i++) {
        nxt1.insert({x1+dx[i], y1+dy[i]});
        nxt2.insert({x2+dx[i], y2+dy[i]});
    }
    for(auto& a: nxt1) {
        for(auto& b: nxt2) {
            if(a == b) {
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
}