#include<iostream>

using namespace std;

int n;
int arr[1001];
int dp[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    dp[1] = arr[1];
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            dp[i] = max(dp[i], dp[j] + arr[i-j]);
        }
    }
    // for(int i = 1; i<= n; i++) {
    //     cout << dp[i] << " ";
    // }
    cout << dp[n];
}