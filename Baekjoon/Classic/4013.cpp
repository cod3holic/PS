#include <bits/stdc++.h>

using namespace std;

int n, m, s, p;
int ATM[500010];
vector<int> E[500010];

int dfsn[500010];
bool finished[500010];
stack<int> st;
int dfs_cnt, scc_cnt;
vector<vector<int>> scc;
int scc_index[500010];

vector<int> sccE[500010];
bool has_terminal[500010];
bool reachable[500010];
int indegree[500010];
int max_money[500010];
queue<int> q;

int dfs(int k) { // scc 제작을 위한 dfs
    st.push(k);
    dfsn[k] = ++dfs_cnt;
    int ret = dfsn[k];
    for (auto &&next : E[k])
    {
        if(finished[next]) continue;
        if(dfsn[next]) ret = min(ret, dfsn[next]);
        else ret = min(ret, dfs(next));
    }
    if(ret == dfsn[k]) {
        vector<int> S;
        while(true) {
            int t = st.top(); st.pop();
            finished[t] = true;
            S.push_back(t);
            scc_index[t] = scc_cnt;
            if(t == k) break;
        }
        scc.push_back(S);
        ++scc_cnt;
    } 
    return ret;
}

void dfs2(int now) {
    if(finished[now]) return;
    finished[now] = true;
    for (auto &&next : sccE[now])
    {
        reachable[next] = true;
        dfs2(next);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    while(m--) {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
    }
    
    for (int i = 1; i <= n; i++) // step 1: scc 만들기
        if(!finished[i]) dfs(i);
    
    for (int i = 1; i <= n; i++) { // scc별로 ATM 합 계산
        int t;
        cin >> t;
        ATM[scc_index[i]] += t;
    }

    cin >> s >> p;

    for (int i = 1; i <= n; i++) { // scc간의 엣지 sccE 만들기
        int now = scc_index[i];
        for (auto next : E[i])
        {
            next = scc_index[next];
            if(now != next) {
                sccE[now].push_back(next);
                ++indegree[next];
            }
        }
    }

    fill(finished, finished+500010, false);
    reachable[scc_index[s]] = true;
    dfs2(scc_index[s]);
    
    while (p--) // scc안에 terminal이 있다면 has_terminal = true;
    {
        int t;
        cin >> t;
        has_terminal[scc_index[t]] = true;
    }

    for (int i = 0; i < scc_cnt; i++)
        max_money[i] = ATM[i];
    
    for (int i = 0; i < scc_cnt; i++)
        if(indegree[i] == 0) q.push(i);
    
    while(!q.empty()) { // step 2: scc 간 위상정렬
        int& now = q.front(); q.pop();
        for (auto next : sccE[now])
        {
            if(reachable[now] && reachable[next])
                max_money[next] = max(max_money[next], max_money[now] + ATM[next]);
            if(--indegree[next]==0) {
                q.push(next);
            }
        }
    }

    int M = 0;
    for (int i = 0; i < scc_cnt; i++)
        if(reachable[i] && has_terminal[i]) M = max(M, max_money[i]);
    cout << M;
}