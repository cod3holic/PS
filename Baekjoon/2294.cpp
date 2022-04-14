#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

int n, k;
int dp[10001];
int arr[101];

const int INF = 2e9;

int main() {
    cin >> n >> k;
    fill(dp, dp+k+1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    
    sort(arr, arr+n);
    for (int i = 1; i <= n; i++)
        for (int j = arr[i]; j <= k; j++)
            dp[j] = min(dp[j-arr[i]]+1, dp[j]);
    
    cout << (dp[k] == INF ? -1 : dp[k]);
}
