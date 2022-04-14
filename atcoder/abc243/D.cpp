#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, x;
deque<char> st;

int main() {
    cin >> n >> x;
    string str;
    cin >> str;
    for (auto &&i : str)
    {
        if(i == 'U') {
            if(!st.size() || st.back() == 'U') st.push_back('U');
            else st.pop_back();
        }
        else if(i == 'L') {
            st.push_back('L');
        }
        else if(i == 'R') {
            st.push_back('R');
        }
    }
    
    ll ans = x;
    for (auto &&i : st)
    {
        if(i == 'U') ans >>= 1;
        else if(i == 'L') ans <<= 1;
        else if(i == 'R') {
          ans <<= 1;
          ans++;  
        }
    }
    cout << ans;
}