#include <bits/stdc++.h>

using namespace std;

int n;
int arr[200001];

int main() {
    deque<pair<int, int>> dq;
    cin >> n;
    int t;
    int lv = 1;
    while(n--) {
        cin >> t;
        if(dq.size() == 0) {
            dq.push_back({t, 1});
            lv = 1;
            cout << dq.size() << "\n";
            continue;
        }
        if(t == dq.back().first) lv++;
        else lv = 1;
        dq.push_back({t, lv});
        if(lv == t) {
            dq.erase(dq.end()-t, dq.end());
            lv = dq.size() ? dq.back().second : 1;
        }
        cout << dq.size() << "\n";
}