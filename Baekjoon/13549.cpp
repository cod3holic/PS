#include<iostream>
#include<queue>
#include<vector>
#include<tuple>

using namespace std;

const int INF = 2e9;

int n, k;
int dist[100001];
priority_queue<pair<int, int>> pq;

bool isValid(int x) {
    if(x < 0 || x > 100000) return false;
    return true;
}

int main() {
    cin >> n >> k;
    fill(dist, dist+100001, INF);
    pq.push({0, n}); dist[n] = 0;
    while(!pq.empty()) {
        int a, w;
        tie(w, a) = pq.top(); pq.pop();
        if(a == k) break;
        pair<int, int> nxts[3] = {{a+1, 1}, {a-1, 1}, {2*a, 0}};
        for(auto nxt: nxts) {
            int b, c;
            tie(b, c) = nxt;
            if(isValid(b)) {
                if(dist[b] > dist[a] + c) {
                    dist[b] = dist[a] + c;
                    pq.push({-dist[b], b});
                }
            }
        }
    }
    cout << dist[k];
}