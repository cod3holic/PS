#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 2e9;
queue<tuple<int, int, int>> q;
bool inQ[2002][2002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int s;
    cin >> s;
    q.push({0, 0, 1});
    while(!q.empty()) {
        int time, clip, screen;
        tie(time, clip, screen) = q.front(); q.pop();
        // cout << time;
        if(screen == s) {
            cout << time;
            break;
        }
        if(screen <= 1000) {
            if(!inQ[screen][screen]) {
                q.push({time+1, screen, screen});
                inQ[screen][screen] = true;
            }
        }
        if(screen+clip <= 2000) {
            if(!inQ[clip][screen+clip]) {
                q.push({time+1, clip, screen+clip});
                inQ[clip][screen+clip] = true;
            }
        }
        if(screen-1 > 0) {
            if(!inQ[clip][screen-1]) {
                q.push({time+1, clip, screen-1});
                inQ[clip][screen-1] = true;
            }
        }
    }
}