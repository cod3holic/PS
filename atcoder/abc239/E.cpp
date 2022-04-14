#include <bits/stdc++.h>

using namespace std;

pair<int, int> node[100110];
int n, q;
vector<int> footprint;
vector<int> P[100110];
vector<int> E[100110];
int arr[100110];
bool visited[100110];

void tour(int t) {
    visited[t] = true;
    int start = footprint.size();
    footprint.push_back(t);
    for (auto &&nxt : E[t]) {
        if(!visited[nxt]) tour(nxt);
    }
    footprint.push_back(t);
    int end = footprint.size();
    vector<int> temp(footprint.begin() + start, footprint.end());
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    for(int i = 0; i < temp.size(); i++) {
        temp[i] = arr[temp[i]];
    }
    sort(temp.begin(), temp.end(), greater<>());
    P[t] = temp;
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    tour(1);
    
    while(q--) {
        int v, k;
        cin >> v >> k;
        cout << P[v][k-1] << "\n";
    }
}