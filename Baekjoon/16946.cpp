#include<iostream>
#include<utility>
#include<tuple>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int n, m;
int arr[1000][1000];
int dp[1000][1000];
pair<int, int> uf[1000][1000];
bool visited[1000][1000];

bool isvalid(int a, int b) {
    if(a < 0 || a >= n) return false;
    if(b < 0 || b >= m) return false;
    return true;
}

void init() {
    for(int i = 0; i < 1000; i++) {
        for(int j = 0; j < 1000; j++) {
            uf[i][j] = {i, j};
        }
    }
}

pair<int, int> find(int a, int b) {
    int p, q;
    while(true) {
        tie(p, q) = uf[a][b];
        if(p == a && q == b) break;
        a = p, b = q;
    }
    return {p, q};
}

void merge(int ha, int hb, int a, int b) {
    tie(ha, hb) = find(ha, hb);
    tie(a, b) = find(a, b);
    uf[a][b].first = uf[ha][hb].first;
    uf[a][b].second = uf[ha][hb].second;
}

int dfs(int a, int b, int ha, int hb) {
    merge(ha, hb, a, b);
    visited[a][b] = true;
    int ret = 1;
    for(int i = 0; i < 4; i++) {
        int na = a+dy[i], nb = b+dx[i];
        if(isvalid(na, nb)) {
            if(arr[na][nb] == 0 && !visited[na][nb]) {
                ret += dfs(na, nb, ha, hb);
            }
        }
    }
    if(a == ha && b == hb) dp[ha][hb] = ret;
    return ret;
}

int adj(int a, int b) {
    if(arr[a][b] == 0) return 0;
    int ret = 1;
    vector<pair<int, int>> buf;
    for(int i = 0; i < 4; i++) {
        int na = a+dy[i], nb = b+dx[i];
        if(isvalid(na, nb)) {
            tie(na, nb) = find(na, nb);
            bool flag = true;
            for(auto& item: buf)
                if(item.first == na && item.second == nb)
                    flag = false;
            if(flag) {
                buf.push_back({na, nb});
                ret += dp[na][nb];
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
    init();
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(arr[i][j] == 0 && !visited[i][j])
                dfs(i, j, i, j);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int a, b;
            tie(a, b) = find(i, j);
            cout << adj(a, b) % 10;
        }
        cout << "\n";
    }
}