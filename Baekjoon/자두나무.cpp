#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 2e9;
int t, w;
int arr[1000];
int dp[1000][30][2];

int func(int k, int v, int tree) {
    if(k == t) return 0;
    int& ret = dp[k][v][tree];
    if(ret) return ret;
    ret = max(ret, func(k+1, v, tree));
    if(v > 0) 
        ret = max(ret, func(k+1, v-1, 1-tree));
    ret += (arr[k] == tree);
    // cout << k << v << tree << ret << "\n";
    return ret;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t >> w;
    for(int i = 0; i < t; i++) {
        cin >> arr[i];
        arr[i]--;
    }
    cout << max(func(0, w, 0), func(0, w-1, 1));
}