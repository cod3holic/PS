#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> E[50001];
int tree[50001];
int depth[50001];
int visited[50001];

void dfs(int node, int p) {
    if(visited[node]) return;
    visited[node] = true;
    tree[node] = p;
    depth[node] = depth[p] + 1;
    for (auto &&v : E[node])
        dfs(v, node);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fill(depth, depth, 2e8);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    dfs(1, 0);
    cin >> m;
    while(m--) {
        int a, b;
        cin >> a >> b;
        if(depth[a]>depth[b]) swap(a, b);
        int d = depth[b] - depth[a];
        while (d--) b = tree[b];
        while (a != b) a = tree[a], b = tree[b];
        cout << a << "\n";
    }
}