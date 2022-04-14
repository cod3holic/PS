#include <iostream>
#include <queue>
#include <utility>
#include <tuple>

using namespace std;

int n, k;
queue<pair<int, int>> q;
bool inQ[100001];

bool isvalid(int t) {
    if(t < 0 || t > 100000) return false;
    return true;
}

int main() {
    int ans;
    cin >> n >> k;
    q.push({n, 0});
    while(!q.empty()) {
        int a, t;
        tie(a, t) = q.front(); q.pop();
        if(a == k) {
            ans = t;
            break;
        }
        int nxt[3] = {a+1, a-1, 2*a};
        for(auto b: nxt) {
            if(isvalid(b)) {
                if(!inQ[b]) {
                    q.push({b, t+1});
                    inQ[b] = true;
                }
            }
        }
    }
    cout << ans;
}