/**
 * Strongly Connected Component
 * kosaraju algorithm
 */


#include <bits/stdc++.h>

using namespace std;

int v, e;
vector<int> E[10001];
vector<int> RE[10001];
stack<int> st;
bool visited[10001];
vector<vector<int>> scc;

void dfs1(int k) {
    if(visited[k]) return;
    visited[k] = true;
    for (auto &&n : E[k])
        dfs1(n);
    st.push(k);
}

void dfs2(int k, int s) {
    if(visited[k]) return;
    visited[k] = true;
    scc[s].push_back(k);
    for (auto &&n : RE[k])
        dfs2(n, s);
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
        RE[b].push_back(a);
    }

    fill(visited, visited+10001, false);
    for (int i = 1; i <= v; i++)
        if(!visited[i]) dfs1(i);
    
    fill(visited, visited+10001, false);
    int i = 0;
    while(!st.empty()) {
        int k = st.top(); st.pop();
        if(!visited[k]) {
            scc.resize(i+1);
            dfs2(k, i);
            i++;
        }
    }

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