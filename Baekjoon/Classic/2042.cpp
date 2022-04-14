#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m, k;
ll origin[1000001];
ll tree[1000001];

void add(int k, ll t) {
    while (k<=n)
    {
        tree[k] += t;
        k += k & -k;
    }
}

ll subsum(int k) {
    ll s = 0;
    while (k >= 1)
    {
        s += tree[k];
        k -= k & -k;
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        ll t;
        cin >> t;
        add(i, t); 
    }
    
    while (m+k--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            add(b, c-(subsum(b)-subsum(b-1)));
        }
        else if (a == 2) {
            cout << subsum(c) - subsum(b-1) << "\n";
        }
    }
    
}