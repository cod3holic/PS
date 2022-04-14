/**
 * 21.12.09
 * 냅색 문제 - DP, 2^n으로 분할
 */

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> w, v;
int dp[6301][10001];

int f(int t, int cost) {
    if(t < 1) return 0;
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

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        int t = 1;
        while (c > 0)
        {
            t = min(t, c);
            w.push_back(a*t);
            v.push_back(b*t);
            c -= t;
            t <<= 1;
        }
    }

    cout << f(w.size(), m);
}