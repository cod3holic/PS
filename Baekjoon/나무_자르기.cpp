#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> arr;
ll n, m;

ll sum_slice(ll k) {
    ll ret = 0;
    for (int i = 0; i < n; i++)
    {
        ret += (arr[i]-k > 0 ? arr[i]-k : 0);
    }
    return ret;
}

ll binary(ll a, ll b) {
    ll mid;
    while (a < b)
    {
        mid = (a+b)/2;
        ll k = sum_slice(mid);
        if(k < m) {
            b = mid-1;
        }
        else if(k > m) {
            a = mid+1;
        }
        else {
            return mid;
        }
    }
    return mid; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    arr.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << binary(1, 2000000000);
}