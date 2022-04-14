/**
 * Inversion Count with Segment Tree
 * reference: https://barbera.tistory.com/41
 * 
 * order array [ 1 2 3 4 5 ]
 *                   ?
 * elems array [ 2 4 1 2 3 ]
 */

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
ll cnt;
int fenwick[500001];
unordered_map<int, int> order;

void add(int k) {
    while(k<=n) {
        fenwick[k] += 1;
        k += k & -k;
    }
}

int subsum(int k) {
    int ret = 0;
    while(k > 0) {
        ret += fenwick[k];
        k -= k & -k;
    }
    return ret;
}

int find(int a, int b) {
    return subsum(b) - subsum(a);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        order.insert({t, i});
    }
    for (int i = 0; i < n; i++)
    {
        int key, o;
        cin >> key;
        o = order.find(key)->second;
        cnt += subsum(n) - subsum(o);
        add(o);
    }
    cout << cnt;
}