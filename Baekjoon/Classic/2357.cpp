/**
 * 업데이트 없는 세그먼트 트리 기본
 * V n^2을 구하는 방법
 */


#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9; 
int mintree[300300];
int maxtree[300300];

int n, n2, m;
int segmax;

int findmax(int a, int b) {
    a += n2;
    b += n2;
    int m = 0;
    while (a <= b)
    {
        if(a%2 == 1) m = max(m, maxtree[a++]); 
        if(b%2 == 0) m = max(m, maxtree[b--]);
        a >>= 1;
        b >>= 1;
    }
    return m;
}

int findmin(int a, int b) {
    a += n2;
    b += n2;
    int m = INF;
    while (a <= b)
    {
        if(a%2 == 1) m = min(m, mintree[a++]); 
        if(b%2 == 0) m = min(m, mintree[b--]);
        a >>= 1;
        b >>= 1;
    }
    return m;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    int k = n;
    n2 = 1;
    while(k >>= 1) n2 <<= 1;
    if(n2 != n) n2 <<= 1;
    segmax = n2*2;
    fill(mintree, mintree+300300, INF);
    fill(maxtree, maxtree+300300, 0);
    for (int i = 0; i < n; i++)
    {
        int t; 
        cin >> t;
        mintree[n2+i] = t;
        maxtree[n2+i] = t;
    }

    for (int i = n2-1; i > 0; i--) // tree init
    {
        mintree[i] = min(mintree[i*2], mintree[i*2+1]);
        maxtree[i] = max(maxtree[i*2], maxtree[i*2+1]);
    }

    while(m--) {
        int a, b;
        cin >> a >> b;
        cout << findmin(a-1, b-1) << " " << findmax(a-1, b-1) << "\n";
    }
}