
// https://degurii.tistory.com/164

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
ll k;
/*
aazz 0
azaz 1
azza 2
zaaz 3
zaza 4
zzaa 5

aaazz
aazaz
aazza
azaaz
azaza
azzaa
*/
const ll INF = 10000000000;
ll dp[201][101];

ll comb(int a, int b) {
    ll& ret = dp[a][b];
    if(ret) return ret;
    if(a == b || b == 0) ret = 1;
    else ret = comb(a-1, b) + comb(a-1, b-1);
    return ret;
}

void func(int n, int m, ll t) {
    if(n+m == 0) return;
    int sub = n+m-1;

    if(t < a) {
        cout << 'a';
        func(n-1, m, t%a);
    }
    else {
        cout << 'z';
        func(n, m-1, t%a);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    if(comb(n+m, n) < k) { cout << -1; return 0; }
    func(n, m, k-1);
}