#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int dp[31];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    dp[0] = 1;
    dp[2] = 3;
    for (int i = 4; i <= n; i+=2)
    {
        dp[i] += dp[i-2]*3;
        for (int j = 0; j <= i-4; j+=2)
            dp[i] += dp[j]*2;
    }
    cout << dp[n];
}