/**
 * SCC DAG에서 사이클을 만들어서 다시 하나의 scc로 묶는 최소의 간선의 개수는?
 */

#include <bits/stdc++.h>
#define MAXN 20001

using namespace std;

int n, m;
vector<int> E[MAXN];
vector<vector<int>> scc;
stack<int> st;
int dfsn[MAXN];
bool finished[MAXN];
int scc_index[MAXN];
int dfs_cnt, scc_cnt;
int indegree[MAXN], outdegree[MAXN];

int dfs(int k) {
    st.push(k);
    int ret = dfsn[k] = ++dfs_cnt;
    for (auto &&next : E[k]) {
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

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        E[i].clear();
    scc.clear();
    fill(finished, finished+MAXN, false);
    fill(scc_index, scc_index+MAXN, 0);
    fill(dfsn, dfsn+MAXN, 0);
    dfs_cnt = 0, scc_cnt = 0;

    while(m--) {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) // step1: SCC (tarjan algorithm)
        if(!finished[i]) dfs(i);
    
    fill(indegree, indegree+MAXN, 0);
    fill(outdegree, outdegree+MAXN, 0);
    int indeg_cnt = 0, outdeg_cnt = 0;
    for (int i = 1; i <= n; i++) // step2: SCC DAG의 indegree, outdegree 중 0의 개수가 많은 것 카운트 출력
    {
        int now = scc_index[i];
        for (auto next : E[i])
        {
            next = scc_index[next];
            if(now == next) continue;
            if(indegree[next] == 0) ++indeg_cnt;
            if(outdegree[now] == 0) ++outdeg_cnt;
            indegree[next]++;
            outdegree[now]++;
        }
    }

    if(scc_cnt == 1) cout << "0\n"; // 하나의 컴포넌트일 때, 엣지케이스
    else cout << max(scc_cnt-indeg_cnt, scc_cnt-outdeg_cnt) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--) solve();
}