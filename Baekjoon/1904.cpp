#include <bits/stdc++.h>
#define MOD 15746

using namespace std;

int n;
int dp[1000000];

int main() {
    cin >> n;
    dp[0] = 1, dp[1] = 2;
    for(int i = 2; i < n; i++)
        dp[i] = (dp[i-2] + dp[i-1]) % MOD;
    cout << dp[n-1];
}