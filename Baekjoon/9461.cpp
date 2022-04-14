#include<iostream>

using namespace std;

int n;
long long dp[101];

void solve() {
    cin >> n;
    cout << dp[n] << "\n";
}

int main() {
    int t;
    cin >> t;
    
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    for(int i = 6; i <= 100; i++) {
        dp[i] = dp[i-1] + dp[i-5];
    }
    
    while(t--) solve();
}