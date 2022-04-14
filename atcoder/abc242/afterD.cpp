#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int q;
string str;

ll func(ll t, ll k) {
    if(k == 0) return (str[0]-'A'+t%3)%3;
    if(t == 0) return str[k]-'A';
    return (func(t-1, k/2)+1+k%2)%3;
}

int main() {
    cin >> str >> q;
    while (q--)
    {
        ll t, k;
        cin >> t >> k;
        cout << (char)(func(t, k-1)+'A') << "\n";
    }
}