#include<iostream>

using namespace std;

typedef long long ll;

int n;
ll dp[100][100];
int arr[100][100];

bool isvalid(int a, int b) {
    if(a < 0 || a >= n) return false;
    if(b < 0 || b >= n) return false;
    return true;
}

ll dfs(int a, int b) {
    ll& ret = dp[a][b];
    if(ret != -1) return ret;
    if(arr[a][b] == 0) return 0;
    // cout << a << " " << b << "\n";
    ll val = 0;
    for (int i = 0; i < 2; i++)
    {
        int nxt[2] = {a, b};
        nxt[i] += arr[a][b];
        int x = nxt[0], y = nxt[1];
        // cout << x << " " << y << "\n";
        if(isvalid(x, y)) {
            val += dfs(x, y);
        }
    }
    ret = val;
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    
    fill(dp[0], dp[0]+100*100, -1);
    dp[n-1][n-1] = 1;
    cout << dfs(0, 0) << "\n";

}