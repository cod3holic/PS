// https://byeo.tistory.com/entry/boj5419-%EB%B6%81%EC%84%9C%ED%92%8D
// 진짜진짜 좋은 문제다.


#include <bits/stdc++.h>
#define MAXN 75000

typedef long long ll;

using namespace std;
int n;
int segbase;
ll segtree[MAXN * 4];

void update(int k, int val) {
    k += segbase;
    segtree[k] = val;
    while(k >>= 1)
        segtree[k] = segtree[2*k] + segtree[2*k+1];
}

ll query(int a, int b) {
    a += segbase, b += segbase;
    ll sum = 0;
    while(a <= b) {
        if(a%2 == 1) sum += segtree[a++];
        if(b%2 == 0) sum += segtree[b--]; 
        a >>= 1, b >>= 1;
    }
    return sum;
}

void solve() {
    cin >> n;
    fill(segtree, segtree+MAXN*4, 0);
    pair<int, int> arr[n], order[n];
    vector<int> comp;
    comp.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
        comp[i] = arr[i].second = -arr[i].second;
    }
    sort(arr, arr+n);
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    segbase = 1;
    while(segbase < comp.size()) segbase *= 2;
    ll ans = 0;
    for (auto &&[x, y] : arr)
    {
        int cy = lower_bound(comp.begin(), comp.end(), y) - comp.begin();
        ans += query(0, cy);
        update(cy, segtree[segbase+cy]+1);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--) solve();
}