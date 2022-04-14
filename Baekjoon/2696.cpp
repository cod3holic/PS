#include<iostream>
#include<algorithm>
#include<deque>

using namespace std;

void solve() {
    int m;
    cin >> m;
    deque<int> arr;
    cout << (m+1)/2 << "\n";
    for (int i = 1; i <= m; i++) {
        int t;
        cin >> t;
        arr.insert(lower_bound(arr.begin(), arr.end(), t), t);
        if(i%2) cout << arr[arr.size()/2] << " ";
        if(i%20 == 0) cout << "\n"; 
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
}