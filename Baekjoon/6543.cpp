#include <bits/stdc++.h>

using namespace std;

int n, m;

int dfsn[5001];
vector<int> E[5001];
stack<int> st;
bool finished[5001];
int dfscnt, sinkcnt;
vector<vector<int>> scc;
vector<int> depth;

int dfs(int k) {
    st.push(k);
    dfsn[k] = ++dfscnt;
    int ret = dfsn[k];
    for (auto &&next : E[k])
    {
        if(finished[next]) continue;
        if(dfsn[next]) ret = min(ret, dfsn[next]);
        else ret = min(ret, dfs(next));
    }
    if(dfsn[k] == ret) {
        vector<int> s;
        while (true)
        {
            int t = st.top(); st.pop();
            finished[t] = true;
            s.push_back(t);
            dfsn[t] = k;
            if(t == k) break;
        }
        scc.push_back(s);
    }
    return ret;
}

void sinkdfs(int k) {
    if(finished[k]) return;
    finished[k] = true;
    sinkcnt++;
    for (auto &&next : E[k])
        sinkdfs(next);
}

bool solve() {
    cin >> n;
    if(n == 0) return false;
    cin >> m;
    for (int i = 1; i <= n; i++)
        E[i].clear();
    scc.clear();
    dfscnt = 0;
    fill(dfsn, dfsn+5001, 0);
    fill(finished, finished+5001, false);

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
    }

    for (int i = 1; i <= n; i++)
        if(!finished[i]) dfs(i);
    
    vector<int> bottom;
    for (int i = 0; i < scc.size(); i++)
    {
        auto&& S = scc[i];
        fill(finished, finished+5001, false);
        sinkcnt = 0;
        sinkdfs(S[0]);
        if(sinkcnt == S.size()) {
            for (auto &&item : S)
                bottom.push_back(item);
        }
    }
    sort(bottom.begin(), bottom.end());
    for (auto &&i : bottom)
        cout << i << " ";
    cout << "\n";
    
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(solve());
}