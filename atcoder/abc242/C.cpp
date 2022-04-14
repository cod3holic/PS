#include <bits/stdc++.h>
#define MOD 998244353

using namespace std;

int n;
int dp[1000001][10];

bool isvalid(int k) {
    if(k < 1 || k > 9) return false;
    return true;
}

int func(int idx, int k) {
    if(idx == n-1) return 1;
    int& ret = dp[idx][k];
    if(ret != -1) return ret;
    ret = 0;
    int nxts[3] = {k-1, k, k+1};
    for(auto&& nxt: nxts) {
        if(isvalid(nxt)) {
            ret = (func(idx+1, nxt) + ret) % MOD;
        }
    }
    return ret;
}

int main() {
    cin >> n;
    int sum = 0;
    fill(dp[0], dp[0]+1000001*10, -1);
    for (int i = 1; i < 10; i++)
        sum = (func(0, i) + sum) % MOD;
    cout << sum;
}