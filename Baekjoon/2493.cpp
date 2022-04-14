#include <bits/stdc++.h>

using namespace std;

int n;
int arr[500000];
int ans[500000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        while(!st.empty()) {
            int t, _;
            tie(t, _) = st.top(); 
            if(t >= k) break; 
            st.pop();    
        }
        if(!st.empty()) ans[i] = st.top().second+1;
        st.push({k, i});
    }
    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    
}