#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef priority_queue<pii> pq;

const int INF = 2e30;

int v, e, s;
vector<pii> E[20001];
bool visited[20001];
int dist[20001];
pq q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> v >> e;
    cin >> s;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        E[a].push_back({b, w});
    }

    fill(dist, dist+20001, INF); dist[s] = 0;
    fill(visited, visited+20001, false);
    q.push({0, s});
    while (!q.empty())
    {
        int a = q.top().second; q.pop();
        if(visited[a]) continue;
        visited[a] = true;
        for (auto &&edge : E[a])
        {
            int b, w;
            tie(b, w) = edge;
            if(dist[b] > dist[a] + w) {
                dist[b] = dist[a] + w;
                q.push({-dist[b], b});
            }
        }
    }

    for (int i = 1; i <= v; i++) {
        if (dist[i] == INF) { cout << "INF\n"; continue; }
        cout << dist[i] << "\n";
    }
}