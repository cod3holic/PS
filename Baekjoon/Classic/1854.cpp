/**
 * 다익스트라 응용
 * https://stackoverflow.com/questions/7208720/finding-kth-shortest-paths
 * https://justicehui.github.io/ps/2019/04/10/BOJ1854/
 * 
 * 깊게 생각해보자.
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 9e18;

int n, m, k;
vector<pair<int, int>> E[1001];
priority_queue<ll> dist[1001];
priority_queue<tuple<ll, int>> q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        E[a].push_back({b, c});
    }

    q.push({0, 1}); dist[1].push(0);
    
    while(!q.empty()) {
        auto item = q.top(); q.pop();
        int d, a;
        tie(d, a) = item;
        d = -d;
        for (int i = 0, e = E[a].size(); i < e; i++)
        {
            int b, w; ll cost;
            tie(b, w) = E[a][i];
            cost = w + d;
            if(dist[b].size() < k) {
                dist[b].push(cost);
                q.push({-cost, b});
            }
            else {
                if(dist[b].top() > cost) {
                    dist[b].pop(); dist[b].push(cost);
                    q.push({-cost, b});
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if(dist[i].size() == k) {
            cout << dist[i].top() << "\n";
        }
        else cout << "-1\n";
    }
}


/*
에시 
4 6 2
1 2 1
1 3 10
2 3 1
3 2 1
2 4 1
3 4 10


*/