/**
 * SPFA, 여러가지 간선
 */


#include <bits/stdc++.h>

using namespace std;

const int INF = 2e30;

int W, H;
int yard[32][32]; // 0: 묘비 or 갈수없는 지역, 1: 잔디, 2: 유령구멍
tuple<int, int, int> ghost[32][32];
bool inQ[32][32];
int spfa[32][32];
int cycle[32][32];
bool walkCycle;
queue<pair<int, int>> q;

void solve() {
    fill(spfa[0], spfa[0]+1024, INF);
    fill(cycle[0], cycle[0]+1024, 0);
    fill(inQ[0], inQ[0]+1024, false);
    while (!q.empty()) q.pop();
    walkCycle = false;

    spfa[1][1] = 0;
    q.push({1, 1}); inQ[1][1] = true;
    while (!q.empty())
    {
        auto item = q.front(); q.pop();
        int a, b;
        tie(a, b) = item;
        inQ[a][b] = false;
        if(a == W && b == H) continue;
        cycle[a][b]++;
        if(cycle[a][b] > W*H) {
            walkCycle = true;
            break;
        } 
        if(yard[a][b] == 2) {
            int nx, ny, w;
            tie(nx, ny, w) = ghost[a][b];
            if(spfa[nx][ny] > spfa[a][b]+w) {
                spfa[nx][ny] = spfa[a][b]+w;
                if(!inQ[nx][ny]) {
                    q.push({nx, ny});
                    inQ[nx][ny] = true;
                }
            }
        }
        else {
            pair<int, int> next[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (auto &&edge : next)
            {
                int dx, dy;
                tie(dx, dy) = edge;
                int nx = a+dx, ny = b+dy;
                if(!yard[nx][ny]) continue;
                if(spfa[nx][ny] > spfa[a][b]+1) {
                    spfa[nx][ny] = spfa[a][b]+1;
                    if(!inQ[nx][ny]) {
                        q.push({nx, ny});
                        inQ[nx][ny] = true;
                    }
                }
            }
        }
    }
    if(walkCycle) cout << "Never";
    else if (spfa[W][H] == INF) cout << "Impossible";
    else cout << spfa[W][H];
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (true)
    {
        cin >> W >> H;
        if(!W && !H) break;
        
        fill(yard[0], yard[0]+1024, 0);
        for (int i = 1; i <= W; i++)
            for (int j = 1; j <= H; j++)
                yard[i][j] = 1;
        
        int G;
        cin >> G;
        while (G--)
        {
            int x, y;
            cin >> x >> y;
            yard[x+1][y+1] = 0;
        }

        int E;
        cin >> E;
        while (E--)
        {
            int x1, x2, y1, y2, w;
            cin >> x1 >> y1 >> x2 >> y2 >> w;
            yard[x1+1][y1+1] = 2;
            ghost[x1+1][y1+1] = {x2+1, y2+1, w};
        }
        solve();
    }
}