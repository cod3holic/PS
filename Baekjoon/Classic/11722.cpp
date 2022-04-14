#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
int dp[1000000];
ll arr[1000000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    fill(dp, dp+1000000, 1);
    m = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(arr[j] < arr[i])
                dp[i] = max(dp[j]+1, dp[i]);
        }
        m = max(m, dp[i]);
    }
    cout << m;
    
}