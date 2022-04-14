#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pp;
typedef priority_queue<pp> pq;

const int INF = 2e9;
int n, m, s, d;
int dist[501];

void dfs(int b, vector<pair<int, int>>* from, bool* visited, vector<pair<int, int>>* E) {
    if(visited[b]) return;
    visited[b] = true;
    for (auto &&before : from[b]) {
        int a, i;
        tie(a, i) = before;
        E[a][i].second = INF;
        dfs(a, from, visited, E);
    }
}

bool solve() {
    vector<pair<int, int>> E[501];
    vector<pair<int, int>> from[501];
    bool visited[501];
    pq q;
    
    cin >> n >> m;
    if(!n && !m) return false;
    cin >> s >> d;

    while(m--) {
        int u, v, p;
        cin >> u >> v >> p;
        E[u].push_back({v, p});
    }

    // s to d dijkstra
    fill(dist, dist+501, INF); dist[s] = 0;
    fill(visited, visited+501, false);
    q.push({0, s});
    while(!q.empty()) {
        int a = q.top().second; q.pop();
        if(visited[a]) continue;
        visited[a] = true;
        int i = 0;
        for (auto &&item : E[a])
        {
            int b, c;
            tie(b, c) = item;
            if(dist[a] + c < dist[b]) {
                dist[b] = dist[a] + c;
                from[b].clear();
                from[b].push_back({a, i});
                q.push({-dist[b], b});
            }
            else if(dist[a] + c == dist[b]) {
                from[b].push_back({a, i});
            }
            i++;
        }
    }

    // make edges in shortest path INF
    fill(visited, visited+501, false);
    dfs(d, from, visited, E);

    // s to d dijkstra
    fill(visited, visited+501, false);
    fill(dist, dist+501, INF); dist[s] = 0;
    q.push({0, s});
    while(!q.empty()) {
        int a = q.top().second; q.pop();
        if(visited[a]) continue;
        visited[a] = true;
        for (auto &&item : E[a])
        {
            int b, c;
            tie(b, c) = item;
            if(c == INF) continue;
            if(dist[a] + c < dist[b]) {
                dist[b] = dist[a] + c;
                q.push({-dist[b], b});
            }
        }
    }

    cout << (dist[d] == INF ? -1 : dist[d]) << "\n";
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(solve());
}