#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1e15;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, s, e;
    vector<pair<int, ll>> E[1001];
    ll dist[1001];
    bool visited[1001] = { false, };
    priority_queue<pair<ll, int>> q;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        E[a].push_back({b, c});
    }
    cin >> s >> e;
    fill(dist, dist+n+1, INF);
    dist[s] = 0;
    q.push({0, s});
    while (!q.empty())
    {
        int _, a;
        tie(_, a) = q.top(); q.pop();
        if(visited[a]) continue;
        visited[a] = true;
        for (auto &&nxt : E[a])
        {
            int b, w;
            tie(b, w) = nxt;
            if(dist[b] > dist[a] + w) {
                dist[b] = dist[a] + w;
                q.push({-dist[b], b});
            }
        }
    }
    cout << dist[e];
}