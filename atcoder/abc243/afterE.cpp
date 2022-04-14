#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 2e13;
int n, m;
ll dist[301][301];
vector<tuple<int, int, int>> E;

int main() {
    cin >> n >> m;

    fill(dist[0], dist[0]+301*301, INF);
    // for (int i = 1; i <= n; i++)
    // {
    //     dist[i][i] = 0;
    // }
    for(int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(c, dist[a][b]);
        dist[b][a] = min(c, dist[b][a]);
        E.push_back({a, b, c});
    }
    
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int cnt = 0;
    for (auto &&item : E)
    {
        int a, b, c;
        tie(a, b, c) = item;
        int unused = 0;
        for (int i = 1; i <= n; i++)
        {
            if(dist[a][i] + dist[i][b] <= c) {
                unused = 1;
                break;
            }
        }
        cnt += unused;
    }
    cout << cnt;
}