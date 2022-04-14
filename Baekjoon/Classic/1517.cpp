#include <bits/stdc++.h>
#define MAXN 500000
using namespace std;

typedef long long ll;

int n, n2;
ll cnt;
ll segtree[4 * MAXN];
vector<int> arr;
map<int, int> order;

void update(int a) {
    a += n2;
    segtree[a] += 1;
    while(a >>= 1)
        segtree[a] = segtree[2*a] + segtree[2*a+1];
}

ll subsum(int a, int b) {
    a += n2; b += n2;
    int ret = 0;
    while(a <= b) {
        if(a%2 == 1) ret += segtree[a++];
        if(b%2 == 0) ret += segtree[b--];
        a >>= 1; b >>= 1;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    n2 = 1;
    while(n2 < n) n2 <<= 1;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        arr[i] = t;
    }
    vector<int> temp(arr);
    sort(temp.begin(), temp.end());

    for (int i = 0, j = 0; i < n; i++) {
        if(order.count(temp[i])) continue;
        order.insert({temp[i], j}); 
        j++;
    }

    cnt = 0;
    for (auto &&ele: arr)
    {
        int o = order.find(ele)->second;
        cnt += subsum(o+1, n2-1);
        update(o);
    }
    cout << cnt;
}