#include <bits/stdc++.h>
#define MOD 1000000003

using namespace std;

typedef long long ll;

const int INF = 2e9;
int dp[1001][1001];
int n, k;

int func(int a, int b) {
    if(a < 1) return 0;
    int& ret = dp[a][b];
    if(ret != -1) return ret;
    ret = 0;
    ret += func(a-2, b-1); ret %= MOD;
    ret += func(a-1, b); ret %= MOD;
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    if(k > n/2+n%2 || k == 0) {
        cout << 0;
        return 0;
    }
    fill(dp[0], dp[0]+1001*1001, -1);
    for(int i = 1; i <= n; i++) {
        dp[i][0] = 1;
        dp[i][1] = i;
    }
    cout << (func(n-3, k-1) + func(n-1, k)) % MOD;
}