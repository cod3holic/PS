#include<iostream>
#define MOD 9901

using namespace std;

int n;
int dp[100001][2];

int main() {
    ios::sync_with_stdio(0);
    
    cin >> n;
    dp[1][0] = 1, dp[1][1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i][0] = (dp[i-1][0] + 2*dp[i-1][1]) % MOD;
        dp[i][1] = (dp[i-1][0] + dp[i-1][1]) % MOD;
    }
    cout << (dp[n][0] + 2*dp[n][1]) % MOD;
}