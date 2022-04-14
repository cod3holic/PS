/**
 * V 무엇을 기준으로 다익스트라를 돌리느냐?
 * V 2개의 기준이 있을 때, 상태를 저장하는 것
 */


#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int dist[101][10001];
    // bool visited[101];
    vector<tuple<int, int, int>> E[101];
    priority_queue<tuple<int, int, int>> q;
    while(k--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        E[a].push_back({b, c, d});
    }

    fill(dist[0], dist[0]+101*10001, INF); dist[1][0] = 0;
    // fill(visited, visited+101, false);
    q.push({0, 0, 1});

    while(!q.empty()) {
        int time, cost, a;
        tie(time, cost, a) = q.top(); q.pop();
        // if(visited[a]) continue;
        // visited[a] = true;
        cost *= -1;
        for (auto &&item : E[a])
        {
            int b, c, d, C;
            tie(b, c, d) = item;
            C = cost + c;
            if(C > m) continue;
            if(dist[a][cost] + d < dist[b][C]) {
                dist[b][C] = dist[a][cost] + d;
                q.push({-dist[b][C], -(cost + c), b});
            }
        }
    }

    int M = INF;
    for (auto &&item : dist[n])
        M = min(M, item);
    if(M == INF) cout << "Poor KCM";
    else cout << M;
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--) solve();
}