#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const int jdx[4] = {2, -2, 0, 0};
const int jdy[4] = {0, 0, -2, 2};

int n, m;
int arr[100][100];
bool visited[100][100][2];

bool isvalid(int a, int b) {
    if(a < 0 || a >= n) return false;
    if(b < 0 || b >= m) return false;
    return true;
}

bool dfs(int a, int b, int jmp, int k) {
    if(a == n-1 && b == m-1 && arr[a][b] <= k)
        return true;
    // cout << a << b << "\n";
    visited[a][b][jmp] = true;
    for(int i = 0; i < 4; i++) {
        int na = a+dy[i], nb = b+dx[i];
        if(isvalid(na, nb)) {
            if(arr[na][nb] <= k && !visited[na][nb][jmp]) {
                if(dfs(na, nb, jmp, k))
                    return true;
            }
        }
    }
    if(jmp > 0) {
        for(int i = 0; i < 4; i++) {
            int na = a+jdy[i], nb = b+jdx[i];
            if(isvalid(na, nb)) {
                if(arr[na][nb] <= k && !visited[na][nb][0]) {
                    if(dfs(na, nb, 0, k)) return true;
                }
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];

    int s = 0, e = 1e9;
    while(s < e) {
        fill(visited[0][0], visited[0][0]+100*100*2, false);
        int mid = (s+e)/2;
        if(arr[0][0] <= mid && dfs(0, 0, 1, mid)) {
            e = mid;
        }
        else {
            s = mid+1;
        }
    }
    cout << s;
    return 0;
}