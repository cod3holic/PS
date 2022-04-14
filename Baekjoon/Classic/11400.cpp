#include <bits/stdc++.h>

using namespace std;

vector<int> E[100001];
int dfsn[100001];
int v, e, dfs_cnt;
vector<pair<int, int>> ans;

int dfs(int k, int par) {
    int ret = dfsn[k] = ++dfs_cnt;
    for (auto next : E[k])
    {
        if(next == par) continue;
        if(dfsn[next]) ret = min(ret, dfsn[next]);
        else {
            int t = dfs(next, k);
            if(dfsn[k] < t) {
                ans.push_back({min(k, next), max(k, next)});
            }
            ret = min(ret, t);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> v >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    dfs(1, 0);
    cout << ans.size() << "\n";
    sort(ans.begin(), ans.end());
    for (auto &[a, b] : ans)
        cout << a << " " << b << "\n";
}