#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 1, 0, 1, -1, -1, 1, 0};

const int INF = 2e9;
int arr[50][50];
bool inQ[50][50];
queue<tuple<int, int, int>> q;
int n, m;

bool isvalid(int a, int b) {
    if(a < 0 || a >= n) return false;
    if(b < 0 || b >= m) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if(arr[i][j]) {
                q.push({0, i, j});
                inQ[i][j] = true;
            }
        }
    }
    int ans = 0;
    while(!q.empty()) {
        int d, y, x;
        tie(d, y, x) = q.front(); q.pop();
        ans = max(ans, d);
        for(int i = 0; i < 8; i++) {
            int ny = y+dy[i], nx = x+dx[i];
            if(!isvalid(ny, nx)) continue;
            if(inQ[ny][nx]) continue;
            q.push({d+1, ny, nx});
            inQ[ny][nx] = true;
        }
    }
    cout << ans;
}