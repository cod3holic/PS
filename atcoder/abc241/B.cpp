#include <bits/stdc++.h>

using namespace std;

int n, m;
int cnt[1001];
map<int, int> mp;
vector<int> arr;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        arr.push_back(k);
    }

    vector<int> order(arr);
    sort(order.begin(), order.end());
    order.erase(unique(order.begin(), order.end()), order.end());
    for(int k: order) {
        mp[k] = 0;
    }
    for (int item: arr)
        mp[item]++;
    
    int i;
    for (i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        mp[t]--;
        if(mp[t] < 0) break;
    }
    if(i == m) cout << "Yes";
    else cout << "No";
}