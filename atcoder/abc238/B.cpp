#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;

int main() {
    int deg = 0;
    cin >> n;
    arr.push_back(0);
    arr.push_back(360);
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        deg = (k+deg)%360;
        arr.push_back(deg);
    }
    sort(arr.begin(), arr.end());
    // for (auto &&item : arr)
    // {
    //     cout << item << " ";
    // }
    
    int ans = 0;
    for (int i = 1; i < arr.size(); i++) {
        ans = max(ans, arr[i]-arr[i-1]);
    }
    cout << ans;
}