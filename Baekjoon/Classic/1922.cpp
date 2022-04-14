#include <bits/stdc++.h>

using namespace std;

vector<tuple<int, int, int>> E;
int tree[1001];
int n, m, cost, cnt;

int find(int t) {
    if(tree[t] == t) return t;
    return find(tree[t]);
}

void unite(int a, int b) {
    int x = find(a);
    int y = find(b);
    tree[x] = tree[y];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == b) continue;
        E.push_back({c, a, b});
    }
    sort(E.begin(), E.end());
    cost = 0; cnt = 0;
    for (int i = 0; i < 1001; i++)
        tree[i] = i;
    
    for (auto &&item : E)
    {
        int a, b, c;
        tie(c, a, b) = item;
        if(find(a) == find(b)) continue;
        unite(a, b);
        cost += c;
    }
    cout << cost;
}