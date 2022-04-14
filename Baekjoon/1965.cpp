#include <iostream>

using namespace std;

int n;
int arr[2000];
int dp[2000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    cin >> n;
    for(int i=0; i < n; i++)
        cin >> arr[i];
    fill(dp, dp+2000, 1);
    for(int i=0; i < n; i++) {
        for(int j=0; j < i; j++) {
            if(arr[j] < arr[i])
                dp[i] = max(dp[j]+1, dp[i]);
        }
        ans = max(dp[i], ans);
    }
    cout << ans;
}