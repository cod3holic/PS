#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
int n, m;
int dist[101][101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    fill(dist[0], dist[0]+101*101, INF);
    for (int i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
    }
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(c, dist[a][b]);
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
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << (dist[i][j] == INF ? 0 : dist[i][j]) << " ";
        }
        cout << "\n";
    }
}