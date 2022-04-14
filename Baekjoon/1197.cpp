#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>

using namespace std;

typedef long long ll;

int group[10001];
int v, e;
vector<tuple<int, int, int>> E;

int find(int k) {
    while(k != group[k]) k = group[k];
    return k;
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    group[b] = group[a];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> v >> e;
    while(e--) {
        int a, b, c;
        cin >> a >> b >> c;
        E.push_back({c, a, b});
    }
    sort(E.begin(), E.end());
    int cost = 0;
    for(int i = 0; i < 10001; i++) group[i] = i;
    for(auto&& item: E) {
        int a, b, c;
        tie(c, a, b) = item;
        if(find(a) == find(b)) continue;
        cost += c;
        merge(a, b);
    }
    cout << cost;
}
