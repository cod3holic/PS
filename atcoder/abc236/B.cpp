#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    cin >> n;
    int m[100001];
    for (int i = 1; i <= n; i++)
        m[i] = 0;
    for (int i = 0; i < 4*n-1; i++) {
        int t;
        cin >> t;
        m[t]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if(m[i] != 4) {
            cout << i;
            break;
        }
    }
    
}