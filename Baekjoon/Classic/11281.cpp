#include <bits/stdc++.h>
#define MAXN 10001

using namespace std;

int n, m;
vector<pair<int, bool>> E[MAXN][2];
stack<pair<int, bool>> st;
int dfsn[MAXN][2];
bool finished[MAXN][2];
int scc_index[MAXN][2];
int dfs_cnt, scc_cnt;
vector<vector<pair<int, bool>>> scc;
int x[MAXN];

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
        vector<pair<int, bool>> S;
        ++scc_cnt;
        while (true)
        {
            auto [t, n] = st.top(); st.pop();
            scc_index[t][n] = scc_cnt; 
            S.push_back({t, n});
            finished[t][n] = true;
            if(idx == t && neg == n) break;
        }
        scc.push_back(S);
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
        if(scc_index[i][0] == scc_index[i][1]) {
            flag = false;
            break;
        }
    }
    cout << flag << "\n";
    if(!flag) return 0;

    fill(x, x+MAXN, -1);
    for (int i = scc_cnt - 1; i >= 0; i--)
        for (auto [item, neg] : scc[i])
            if(x[item] == -1) x[item] = neg;

    for (int i = 1; i <= n; i++)
        cout << x[i] << " ";
}