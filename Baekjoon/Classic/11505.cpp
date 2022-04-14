#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll segtree[3000000];
int n, n2, m, k;

ll mod(ll t) {
    return t % 1000000007;
}

void change(int b, ll c) {
    b += n2;
    segtree[b] = c;
    while(b >>= 1) {
        segtree[b] = mod(segtree[b*2] * segtree[b*2+1]);
    }
}

ll pi(int b, int c) {
    b += n2; c += n2;
    ll ret = 1;
    while(b <= c) {
        if(b%2 == 1) ret = mod(ret * segtree[b++]);
        if(c%2 == 0) ret = mod(ret * segtree[c--]);
        b >>= 1;
        c >>= 1;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    int t = n; n2 = 1;
    while(t >>= 1) n2 <<= 1;
    if(n2 != n) n2 <<= 1;
    fill(segtree, segtree+3000000, 1);
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        segtree[n2+i] = v;  
    }
    for (int i = n2-1; i > 0; i--)
        segtree[i] = mod(segtree[i*2] * segtree[i*2+1]);
    
    while(m+k--) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a==1)
            change(b-1, c);
        else if (a == 2) {
            cout << pi(b-1, c-1) << "\n";
        }
    }
}