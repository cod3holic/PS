#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,n) for(int i=1;i<=n;++i)
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)
using namespace std;

typedef pair<int, int> pii;

vector<pii> arr;
vector<int> fenwick;
int N;

int query(int idx) {
    int ret = 0;
    while (idx) {
        ret += fenwick[idx];
        idx -= idx & -idx;
    }
    return ret;
}

void update(int idx,int val) {
    while (idx <= N) {
        fenwick[idx] += val;
        idx += idx & -idx;
    }
}

int main() {
    FAST;
    cin >> N;
    arr.resize(N);
    fenwick.resize(N + 1);
    rep(i, N) {
        auto& [a, b] = arr[i];
        cin >> a;
        b = i;
    }
    sort(arr.rbegin(), arr.rend());

    long long ans = 0;
    
    for (auto [a, b] : arr) {
        b += 1;
        ans += query(b - 1);
        cout << query(b - 1);
        update(b,1);
        
        /*for (int i = 1; i <= N; i++)
        {
            cout << fenwick[i];
        }*/
        cout << "\n";
    }
    cout << ans;

    return 0;
}

/**
 * @brief 
 * 3 2 1
 * 0 1 2
 * 
 * 1 2 3
 * 2 1 0
 * 
 * 1 2 3
 *     1 
 * 
 * 1 2 3
 * 0 
 * 
 */