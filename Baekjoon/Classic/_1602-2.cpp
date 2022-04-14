// 이것도 아닌듯

#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;
int n, m, q;
int dist[1001][2][1001][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    fill(dist[0][0][0], dist[0][0][0]+1001*1001*2*2, INF);
    
    for (int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;
        dist[i][0][i][1] = c;
    }
    
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][0][b][0] = c;
        dist[b][0][a][0] = c;
        dist[a][1][b][1] = c;
        dist[b][1][a][1] = c;
    }

    for (int i = 1; i <= n; i++) {
        dist[i][0][i][0] = 0;
        dist[i][1][i][1] = 0;
    }
    
    for (int k = 1; k <= n; k++)
    {
        for (int l = 0; l < 2; l++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    for (int t1 = 0; t1 < 2; t1++)
                    {
                        for (int t2 = 0; t2 < 2; t2++)
                        {
                            // 중간노드 (k, l)에 대해서 (i, t1), (j, t2)상의 경로 단축이 가능한가? 
                            if(dist[i][t1][k][l] == INF || dist[k][l][j][t2] == INF) continue;
                            int& cur = dist[i][t1][j][t2];
                            cur = min(cur, dist[i][t1][k][l] + dist[k][l][j][t2]);
                        }
                    }                      
                }   
            }
        }
    }

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << (dist[a][0][b][1] == INF ? -1 : dist[a][0][b][1]) << "\n";
    }
}