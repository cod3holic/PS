// 이거 아닌듯

#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;
int n, n2, m, q;
int dist[1001][1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    n2 = 2*n;
    fill(dist[0], dist[0]+1001*1001, INF);
    for (int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;
        dist[2*i-1][2*i] = c;
    }
    
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        a = 2*a;
        b = 2*b-1;
        dist[a][b] = c;
        dist[b][a] = c;
    }

    for (int i = 1; i <= n2; i++)
        dist[i][i] = 0;
    
    for (int k = 1; k <= n2; k++)
    {
        for (int i = 1; i <= n2; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if(dist[i][k] == INF || dist[k][j] == INF) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }   
        }
    }
    
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << (dist[2*a-1][2*b] == INF ? -1 : dist[2*a-1][2*b]) << "\n";
    }
    
}