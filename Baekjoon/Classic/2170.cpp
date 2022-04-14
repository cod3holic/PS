#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
pair<ll, ll> arr[1000000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        arr[i] = {a, b};
    }
    sort(arr, arr+n);
    
    int k = arr[0].first;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        auto& [a, b] = arr[i];
        if(k >= b) continue;
        if(a > k) k = a;
        ans += b-k;
        k = b;
    }
    cout << ans;
}