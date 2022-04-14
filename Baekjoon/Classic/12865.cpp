/**
 * 21.12.09
 * 냅색 문제 - DP
 */

#include <bits/stdc++.h>

using namespace std;

int n, k;
int w[101], v[101];
int dp[101][100001];

int f(int t, int cost) {
    if(t < 0) return 0;
    int& ret = dp[t][cost];
    if(ret) return ret;
    ret = f(t-1, cost);
    if(cost - w[t-1] >= 0)
        ret = max(f(t-1, cost - w[t-1]) + v[t-1], ret);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];
    
    cout << f(n, k);
}