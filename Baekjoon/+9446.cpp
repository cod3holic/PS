// 좀 더 생각해보세요...

#include<iostream>
#include<unordered_map>
#include<vector>
#include<tuple>
#include<queue>

using namespace std;

const int INF = 2e9;

int n, m;
int arr[10001];
vector<pair<int, int>> E[10001];
priority_queue<pair<int, int>> pq;
int dist[10001];
int degree[]

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        E[a].push_back({b, c});
    }
    pq.push_back({0, 1});
    
}