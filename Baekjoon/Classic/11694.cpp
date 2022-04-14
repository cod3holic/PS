/**
 * 스플라그 그런디 대표적 문제 
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int s = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        s ^= a;
        if(a == 1) cnt++;
    }
    if(cnt == n) {
        if(s == 0) cout << "koosaga";
        else cout << "cubelover";  
    }
    else {
        if(s > 0) cout << "koosaga";
        else cout << "cubelover";
    }
}