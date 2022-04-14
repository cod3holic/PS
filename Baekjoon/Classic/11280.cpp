#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<pair<int, bool>> E[10001][2];
stack<pair<int, bool>> st;
int dfsn[10001][2];
bool finished[10001][2];
int scc[10001][2];
int dfs_cnt, scc_cnt;

int dfs(pair<int, bool> k) {
    auto [idx, neg] = k;  
    st.push({idx, neg});
    int ret = dfsn[idx][neg] = ++dfs_cnt;
    for (auto &&[next, nneg] : E[idx][neg])
    {
        if(finished[next][nneg]) continue;
        if(dfsn[next][nneg]) ret = min(ret, dfsn[next][nneg]);
        else ret = min(ret, dfs({next, nneg}));
    }
    if(ret == dfsn[idx][neg]) {
        ++scc_cnt;
        while (true)
        {
            auto [t, n] = st.top(); st.pop();
            scc[t][n] = scc_cnt; 
            finished[t][n] = true;
            if(idx == t && neg == n) break;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    while(m--) {
        int a, b;
        cin >> a >> b;
        // A or B == not A -> B === not B -> A
        E[abs(a)][!(a < 0)].push_back({abs(b), (b < 0)});
        E[abs(b)][!(b < 0)].push_back({abs(a), (a < 0)});
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 2; j++)
            if(!finished[i][j]) dfs({i, j});
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if(scc[i][0] == scc[i][1]) {
            flag = false;
            break;
        }
    }
    cout << flag;
}