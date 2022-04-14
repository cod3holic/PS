#include <bits/stdc++.h>
#define MAXN 500000

typedef long long ll;
using namespace std;

int n, segbase;
int arr[MAXN];
ll segtree[4 * MAXN];

void update(int k, int v) {
    k += segbase;
    segtree[k] = v;
    while(k >>= 1)
        segtree[k] = segtree[2*k] + segtree[2*k+1];
}

ll query(int a, int b) {
    a += segbase, b += segbase;
    ll ret = 0;
    while (a <= b)
    {
        if(a%2 == 1) ret += segtree[a++];
        if(b%2 == 0) ret += segtree[b--];
        a >>= 1, b >>= 1;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    segbase = 1;
    while(segbase < n) segbase *= 2;

    vector<int> ordered;
    ordered.resize(n);
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        ordered[i] = arr[i] = -t;
    }
    sort(ordered.begin(), ordered.end());

    for (int i = 0; i < n; i++)
    {
        int c = lower_bound(ordered.begin(), ordered.end(), arr[i]) - ordered.begin();
        cout << query(0, c)+1 << "\n";
        update(c, 1);
    }
}