#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 2e9;
int n, m;
priority_queue<pair<ll, int>> pq;
vector<pair<int, int>> E[301];
bool visited[301];
ll dist[301];

int main() {
    
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        E[a].push_back({b, c});
        E[b].push_back({a, c});
    }
    
    fill(dist, dist+301, INF);
    pq.push({0, 1});
    int vcnt = 1, ecnt = 0;
    while (!pq.empty())
    {
        int a, w;
        tie(w, a) = pq.top(); pq.pop();
        if(visited[a]) continue;
        visited[a] = true;
        vcnt++;
        if(vcnt == n) {
            cout << m-ecnt;
            return 0;
        }

    }
    
}