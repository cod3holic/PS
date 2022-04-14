/**
 * SPFA
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef queue<int> qi;

const ll INF = 2e60;

int n, m;
ll spfa[510];
int cycle[510];
bool inQ[510];
vector<pair<ll, ll>> E[510];
qi q;

int main() {    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        E[a].push_back({b, c});
    }

    //spfa
    //인접 노드들에 대해 edge relaxation
    fill(spfa, spfa+n+1, INF);
    spfa[1] = 0;
    bool hascycle = false;
    q.push(1); inQ[1] = true;
    while (!q.empty())
    {
        int a = q.front(); q.pop(); inQ[a] = false;
        if(cycle[a]>=n) {
            hascycle = true;
            break;
        }
        cycle[a]++;
        for (auto &&edge : E[a])
        {
            int b, w;
            tie(b, w) = edge;
            if(spfa[a] + w < spfa[b]) {
                spfa[b] = spfa[a] + w;
                if(!inQ[b]) {
                    q.push(b); inQ[b] = true;
                }
            }
        } 
    }
    

    if(hascycle) {
        cout << "-1";
    }
    else {
        for (int i = 2; i <= n; i++)
            cout << (spfa[i] != INF ? spfa[i] : -1) << "\n";
    }
}
