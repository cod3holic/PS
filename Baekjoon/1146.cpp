// https://www.acmicpc.net/problem/3948 bitmask dp

#include <bits/stdc++.h>
#define MOD 1000000

using namespace std;

int n;
int dp[101][101][2]; // 왼쪽, 오른쪽, is오름차순

int func(int l, int r, bool order) {
    if(l == 0 && r == 0) return 1;
    if(l < 0 || r < 0) return 0;
    int& ret = dp[l][r][order];
    if(ret != -1) return ret;
    ret = 0;
    if(order) {
        for (int i = 0; i < l; i++)
            ret = (ret + func(i, r+l-1-i, !order)) % MOD;
    }
    else {
        for (int i = 0; i < r; i++)
            ret = (ret + func(r+l-1-i, i, !order)) % MOD;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    if(n == 1) {
        cout << 1; return 0;
    }
    int ans = 0;
    fill(dp[0][0], dp[0][0]+100*100*2, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            ans = (ans + func(j-1, n-1-j, 1)) % MOD;
            ans = (ans + func(i, n-1-i-1, 0)) % MOD;
        }
    }
    cout << ans;
}