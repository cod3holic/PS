/**
 * Strongly Connected Component
 * tarjan algorithm
 */

#include <bits/stdc++.h>

using namespace std;

int v, e;
vector<int> E[10001];
stack<int> st;

vector<vector<int>> scc;
bool visited[10001], finished[10001];
int dfsn[10001];
int dfscnt;

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
        vector<int> S;
        while (true)
        {
            int t = st.top(); st.pop();
            S.push_back(t);
            finished[t] = true;
            dfsn[t] = ret;
            if(t == k) break;
        }
        scc.push_back(S);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> v >> e;

    while(e--) {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
    }
    
    for (int i = 1; i <= v; i++)
        if(!finished[i]) dfs(i);
    /*
    for (int i = 1; i <= v; i++)
    {
        cout << dfsn[i] << " ";
    }
    */

    for (auto &&S : scc)
        sort(S.begin(), S.end());
    sort(scc.begin(), scc.end());
    cout << scc.size() << "\n";
    for (auto &&S : scc)
    {
        for (auto &&item : S)
            cout << item << " ";
        cout << "-1\n";
    }
    
}