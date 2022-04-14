#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 2e9;
queue<pair<ll, ll>> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll a, b;
    cin >> a >> b;
    q.push({1, a});
    ll ans = -1;
    while(!q.empty()) {
        ll k, cost;
        tie(cost, k) = q.front(); q.pop();
        if(k == b) {
            ans = cost;
            break;
        }
        if(2*k <= b) q.push({cost+1, 2*k});
        if(10*k+1 <= b)q.push({cost+1, 10*k+1});
    }
    cout << ans;
}