#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> E[100001];
int tree[100001][20];
int depth[100001];
int visited[100001];

void dfs(int node, int p) {
    if(visited[node]) return;
    visited[node] = true;
    tree[node][0] = p;
    depth[node] = depth[p] + 1;
    for (auto &&v : E[node])
        dfs(v, node);
}

void sparse() {
    for (int i = 1; i < 20; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int half = tree[j][i-1];
            tree[j][i] = tree[half][i-1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    dfs(1, 0);
    sparse();
    cin >> m;
    while(m--) {
        int a, b;
        cin >> a >> b;
        if(depth[a]>depth[b]) swap(a, b);
        int d = depth[b] - depth[a];
        for (int i = 19; i >= 0; i--)
        {
            if(d & (1 << i)) {
                b = tree[b][i];
            }
        }
        for (int i = 19; i >= 0; i--)
        {
            if(tree[a][i] != tree[b][i]) {
                a = tree[a][i];
                b = tree[b][i];
            }
        }
        int ans;
        if(a == b) ans = a;
        else ans = tree[a][0];
        cout << ans << "\n";
    }
}