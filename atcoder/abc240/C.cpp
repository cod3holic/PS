#include <bits/stdc++.h>

using namespace std;

int n, x;
int arr1[101];
int arr2[101];
int dp[101][10001];

bool func(int idx, int cor) {
    if(idx == n) {
        return (cor == x);
    }
    int& ret = dp[idx][cor];
    if(ret != -1) return ret;
    ret = 0;
    ret |= func(idx+1, cor+arr1[idx]);
    ret |= func(idx+1, cor+arr2[idx]);
    // cout << idx << ret;
    return ret;
}

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> arr1[i] >> arr2[i];
    fill(dp[0], dp[0]+101*10001, -1);
    bool ans = func(0, 0);
    cout << (ans ? "Yes" : "No");
}