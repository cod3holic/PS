#include<iostream>

using namespace std;

typedef long long ll;

int n, m;
ll dp[501][501];
int arr[501][501];
int signs[2] = {-1, 1};

bool isvalid(int a, int b) {
    if(a < 0 || a >= m) return false;
    if(b < 0 || b >= n) return false;
    return true;
}

ll dfs(int a, int b) {
    ll& ret = dp[a][b];
    if(ret != -1) return ret;
    // cout << a << " " << b << "\n";
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
    ll val = 0;
    for (int i = 0; i < 2; i++)
    {
        for(auto&& s: signs) {
            int nxt[2] = {0, 0};
            nxt[i] += s;
            int x = a+nxt[0], y = b+nxt[1]; // x, y는 인접한 노드
            if(isvalid(x, y) && arr[x][y] > arr[a][b]) {
                val += dfs(x, y);
            }
        }
    }
    ret = val;
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    fill(dp[0], dp[0]+501*501, -1);
    dp[0][0] = 1;
    cout << dfs(m-1, n-1);
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}
