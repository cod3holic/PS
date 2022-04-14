/**
 * 벨만포드 기본
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 2e60;

int n, m;
ll bf[510];
vector<tuple<ll, ll, ll>> E;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    E.resize(m);
    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        E.push_back({a, b, c});
    }

    //bellman ford
    //n-1라운드 동안 edge relaxation
    fill(bf, bf+n+2, INF);
    bf[1] = 0;
    bool hascycle = false;
    for (int i = 0; i < n; i++)
    {
        for (auto &&edge : E)
        {
            ll a, b, c;
            tie(a, b, c) = edge;
            if(bf[a] == INF) continue;
            // if there is walk from 1 to negative cycle
            if(bf[a]+c < bf[b]) {
                if(i == n-1) hascycle = true;
                bf[b] = bf[a]+c;
            }
        }
    }

    if(hascycle) {
        cout << "-1";
    }
    else {
        for (int i = 2; i <= n; i++)
            cout << (bf[i] != INF ? bf[i] : -1) << "\n";
    }
}
