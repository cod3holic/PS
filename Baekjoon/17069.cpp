#include <iostream>

using namespace std;

typedef long long ll;

int n;
ll dp[33][33][3];
bool arr[33][33];

bool isValid(int a, int b) {
    if(a <= 0 || a > n) return false;
    if(b <= 0 || b > n) return false;
    return true;
}

ll dfs(int a, int b, int d) {
    if(!isValid(a, b)) return 0;
    if(a == 1 && b == 2 && d == 0) return 1;
    ll& ret = dp[a][b][d];
    if(ret != -1) return ret;
    ret = 0;
    if(d == 0) {
        if(arr[a][b]) {
            ret += dfs(a, b-1, 0);
            ret += dfs(a, b-1, 2);
        }
    }
    else if(d == 1) {
        if(arr[a][b]) {
            ret += dfs(a-1, b, 1);
            ret += dfs(a-1, b, 2);
        }
    }
    else {
        if(arr[a][b] && arr[a-1][b] && arr[a][b-1]) {
            ret += dfs(a-1, b-1, 0);
            ret += dfs(a-1, b-1, 1);
            ret += dfs(a-1, b-1, 2);
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    fill(dp[0][0], dp[0][0]+33*33*3, -1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            int t;
            cin >> t;
            arr[i][j] = !t;
        }
    
    cout << dfs(n, n, 0) + dfs(n, n, 1) + dfs(n, n, 2);
}