#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

int n, m;
int H[200001];
vector<pair<int, int>> E[200001];
int dist[200001];
int cnt[200001];

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> H[i];
    
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if(H[a] > H[b]) {
            E[a].push_back({b, -(H[a]-H[b])});
            E[b].push_back({a, 2*(H[a]-H[b])});
        }
        else if(H[a] < H[b]) {
            E[a].push_back({b, 2*(H[b]-H[a])});
            E[b].push_back({a, -(H[b]-H[a])});
        }
        else {
            E[a].push_back({b, 0});
            E[b].push_back({a, 0});
        }
    }

    // for (int item = 1; item <= n; item++)
    // {
    //     for (auto &&i : E[item])
    //     {
    //         cout << i.first << " " << i.second << " / ";
    //     }
    //     cout << "\n";
    // }
    

    fill(dist, dist+200001, INF);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while (!q.empty())
    {
        int t = q.front(); q.pop();
        cnt[t]++;
        // cout << t;
        if(cnt[t] == n) break;
        for(auto nxt: E[t]) {
            int nxtt, nxtc;
            tie(nxtt, nxtc) = nxt;
            if(dist[t] + nxtc < dist[nxtt]) {
                // for (int i = 1; i <= n; i++)
                // {
                //     cout << dist[i] << " ";
                // }
                // cout << "\n";
                dist[nxtt] = dist[t] + nxtc;
                q.push(nxtt);
            }
        }
    }

    cout << -1*(*min_element(dist+1, dist+n+1));
    
}