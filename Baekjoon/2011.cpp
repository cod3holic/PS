#include<iostream>
#define MOD 1000000

using namespace std;

int n;
int arr[5001];
int dp[5001];

int input() {
    int i = 0;
    char c;
    while(cin >> c) {
        arr[++i] = c-'0';
    }
    return i;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    n = input();

    if(arr[1] == 0) {
        cout << 0;
        return 0;
    }
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(10 <= 10*arr[i-1]+arr[i] && 10*arr[i-1]+arr[i] <= 26) {
            dp[i] = (dp[i] + dp[i-2]) % MOD;
        }
        if(arr[i] != 0) {
            dp[i] = (dp[i] + dp[i-1]) % MOD;
        }
    }
    // for(int i = 1; i<=n; i++)
    //     cout << dp[i] << " ";
    cout << dp[n];
}