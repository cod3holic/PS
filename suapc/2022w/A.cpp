#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int n, m;
stack<int> st;
bool visited[200001];
vector<vector<int>> group;
vector<int> E[200001];

void dfs(int k, int head) {
    st.push(k);
    visited[k] = true;
    for(auto& nxt: E[k]) {
        if(!visited[nxt]) {
            dfs(nxt, head);
        }
    }
    if(k == head) {
        vector<int> s;
        while (true)
        {
            int t = st.top(); st.pop();
            s.push_back(t);
            if(t == k) break;
        }
        group.push_back(s);
    }
}

int main() {
    cin >> n >> m;
    while(m--) {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        if(!visited[i]) dfs(i, i);
    long long ans = 1;
    for (auto &&g : group)
        ans = (ans * (long long)g.size()) % MOD;
    cout << ans;
}