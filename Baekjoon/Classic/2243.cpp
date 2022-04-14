#include <bits/stdc++.h>

using namespace std;

int t, n2;
int segtree[3000000];

void update(int a, int b) {
    a += n2;
    segtree[a] += b;
    while (a >>= 1)
        segtree[a] = segtree[2*a] + segtree[2*a+1];
}

int find(int node, int a) {
    if(node >= n2) return node;
    int ret;
    if(segtree[node*2] < a)
        ret = find(node*2+1, a-segtree[node*2]);
    else
        ret = find(node*2, a);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    int k = 1000000; n2 = 1;
    do { n2 <<= 1; } while(k >>= 1);
    
    while(t--) {
        int a;
        cin >> a;
        if(a == 1) {
            int b, index;
            cin >> b;
            index = find(1, b)-n2;
            cout << index+1 << "\n";
            update(index, -1);
        }
        else if(a == 2) {
            int b, c;
            cin >> b >> c;
            update(b-1, c);
        }
    }
}