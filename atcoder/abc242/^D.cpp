// https://atcoder.jp/contests/abc242/editorial/3528

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;
 
char nxt[3][2];
string str;
stack<int> st;

void init() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++)
            nxt[i][j] = (i+j+1)%3;
}

char query(ll t, ll k) {
    int i = 0;
    while(t) {
        int idx = k & 1;
        st.push(idx);
        k >>= 1;
        t--;
    }
    
    char start = str[k]-'A';
    // cout << (int)start;
    while(!st.empty()) {
        start = nxt[start][st.top()];
        st.pop();
    }
    return start+'A';
}

int main() {
    int q;
    cin >> str;
    cin >> q;

    init();
    while(q--) {
        ll t, k;
        cin >> t >> k;
        cout << query(t, k-1) << "\n";
    }
}