// https://blog.joonas.io/50
#include <iostream>

using namespace std;

int n, k;
int dp[201][201];

int mod(int k) {
    return k%1000000000;
}

int func(int t, int cnt) {
    if(t == 0) return 1;
    int& ret =  dp[t][cnt];
    if(ret) return ret;
    for (int i = 0; i <= t; i++)
        ret = mod(ret + func(t-i, cnt-1));
    return ret;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        dp[i][1] = 1;
    for (int i = 1; i <= k; i++)
        dp[1][i] = i;
    cout << func(n, k);
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= k; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
}