#include<bits/stdc++.h>
#define MAXN 100000

using namespace std;

const int INF = 2e9;

int n, m, segbase;
int segtree[4 * MAXN];
int arr[MAXN];

int argmin(int a, int b) {
    if(a > b) swap(a, b);
    if(arr[a] > arr[b]) return b;
    else return a;
}

void init() {
    for (int i = 0; i < segbase*2; i++)
        segtree[i+segbase] = i;
    
    for (int i = segbase-1; i > 0; i--)
        segtree[i] = argmin(segtree[i*2], segtree[i*2+1]);
}

void setQuery(int idx, int val) {
    arr[idx] = val;
    idx += segbase;
    while(idx >>= 1) {
        segtree[idx] = argmin(segtree[idx*2], segtree[idx*2+1]);
    }
}

int getQuery(int a, int b) {
    int ret = b;
    a += segbase, b += segbase;
    while (a <= b) {
        if(a%2 == 1) ret = argmin(ret, segtree[a++]);
        if(b%2 == 0) ret = argmin(ret, segtree[b--]);
        a >>= 1, b >>= 1;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    segbase = 1;
    while(segbase < n) segbase <<= 1;
    
    for (int i = 0; i < segbase; i++) {
        if(i < n)
            cin >> arr[i];
        else
            arr[i] = INF;
    }
    init();

    cin >> m;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        if(a == 1)
            setQuery(--b, c);
        else if(a == 2)
            cout << getQuery(--b, --c)+1 << "\n";
    }
    return 0;
}