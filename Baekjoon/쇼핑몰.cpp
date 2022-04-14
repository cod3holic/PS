#include<iostream>
#include<queue>
#include<tuple>

using namespace std;

typedef long long ll;

const int INF = 2e9;
int n, k;
pair<int, int> arr[100000];
priority_queue<tuple<ll, int, int>> pq;
priority_queue<tuple<ll, int, int>> log;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i < k; i++) {
        pq.push({0, -i, 0});
    }
    for(int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    ll t = 0, idx = 0;
    while(!pq.empty()) {
        int endtime, table, id;
        tie(endtime, table, id) = pq.top(); pq.pop();
        endtime = -endtime, table = -table;
        // cout << endtime << " " << table << " " << id << "\n";
        if(t < endtime) t = endtime;
        if(id > 0) log.push({-endtime, table, id});
        if(idx < n) {
            pq.push({-t-arr[idx].second, -table, arr[idx].first});
            idx++;
        } 
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ll a, b, c;
        tie(a, b, c) = log.top(); log.pop();
        // cout << a << " " << b << " " << c << "\n";
        ans += i*c;
    }
    cout << ans;
}