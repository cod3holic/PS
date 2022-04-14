#include<iostream>
#include<queue>
#include<tuple>

using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
const int hdx[8] = {-1, -1, -2, -2, 1, 1, 2, 2};
const int hdy[8] = {-2, 2, -1, 1, -2, 2, -1, 1};

queue<tuple<int, int, int, int>> q;
int k, w, h;
int arr[200][200];
bool inQ[200][200][31];

bool isvalid(int a, int b) {
    if(a < 0 || a >= h) return false;
    if(b < 0 || b >= w) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k;
    cin >> w >> h;
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            cin >> arr[i][j];

    q.push({0, 0, k, 0});
    inQ[0][0][k] = true;
    int ans = -1;
    while(!q.empty()) {
        int a, b, t, cnt;
        tie(a, b, t, cnt) = q.front(); q.pop();
        // cout << a << " " << b << " " << t << " " << cnt << "\n";
        if(a == h-1 && b == w-1) {
            ans = cnt;
            break;
        }
        for(int i = 0; i < 4; i++) {
            int na = a+dy[i], nb = b+dx[i];
            if(isvalid(na, nb)) {
                if(arr[na][nb] == 0 && !inQ[na][nb][t]) {
                    q.push({na, nb, t, cnt+1});
                    inQ[na][nb][t] = true;
                }
            }
        }
        if(t > 0) {
            for(int i = 0; i < 8; i++) {
                int na = a+hdy[i], nb = b+hdx[i];
                if(isvalid(na, nb)) {
                    if(arr[na][nb] == 0 && !inQ[na][nb][t-1]) {
                        q.push({na, nb, t-1, cnt+1});
                        inQ[na][nb][t-1] = true;
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}