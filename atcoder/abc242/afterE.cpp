#include <bits/stdc++.h>
#define MOD 998244353

typedef long long ll;

using namespace std;

int n;
string str;
int target;

void solve() {
    cin >> n >> str;
    target = n/2+n%2;
    ll ans = 0;
    for (int i = 0; i < target; i++) {
        ans *= 26; ans %= MOD;
        ans += str[i]-'A'; ans %= MOD;
    }
    ans++; ans %= MOD;

    string pal(str);
    int a, b;
    a = 0, b = n-1;
    while (a<b)
    {
        pal[b] = pal[a];
        a++, b--;
    }

    if(pal > str) {
        ans += MOD-1; ans %= MOD; // 와씨 이걸 해킹하네
    }
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}