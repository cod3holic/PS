#include<iostream>
#include<vector>

using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int n, m;
int arr[1000][1000];
int visited[1000][1000];
int dp[1000000];

bool isvalid(int a, int b) {
    if(a < 0 || a >= n) return false;
    if(b < 0 || b >= m) return false;
    return true;
}

int dfs(int a, int b, int cnt) {
    visited[a][b] = cnt;
    int ret = 1;
    for(int i = 0; i < 4; i++) {
        int na = a+dy[i], nb = b+dx[i];
        if(isvalid(na, nb)) {
            if(arr[na][nb] == 0 && !visited[na][nb]) {
                ret += dfs(na, nb, cnt);
            }
        }
    }
    return ret;
}

int adj(int a, int b) {
    int ret = 1;
    vector<int> buf;
    for(int i = 0; i < 4; i++) {
        int na = a+dy[i], nb = b+dx[i];
        if(isvalid(na, nb)) {
            int flag = true;
            for(auto item: buf) {
                if(visited[na][nb] == item)
                    flag = false;
            } 
            if(flag) {
                buf.push_back(visited[na][nb]);
                ret += dp[visited[na][nb]];
            }
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < m; j++)
            arr[i][j] = str[j]-'0';
    }

    int cnt = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(arr[i][j] == 0 && !visited[i][j]) {
                dp[cnt] = dfs(i, j, cnt);
                cnt += 1;
            }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 1) cout << adj(i, j) % 10;
            else cout << 0;
        }
        cout << "\n";
    }
    
}