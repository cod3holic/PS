// 이건 또 어캐푸냐...?

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 2e9;
string str;
int k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> str;
    cin >> k;
    int pf = 0, sf = str.size()-k;
    int cnt = 0;
    for(int i = 0; i < k; i++) {
        if(str[pf] == str[sf]) continue;
        cnt++;
        int offset = k - sf;
        if(offset >= 0) {
            int t = str[k-1-offset];
            str[pf] = str[sf] = t;
        }
        else {
            str[pf] = str[sf];
        }
    }
    cout << cnt;
}