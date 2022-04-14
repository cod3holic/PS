#include <iostream>

using namespace std;

typedef long long ll;

int n, l;
ll k;
ll dp[32][32];
ll subsum[33][33];

void init() {
    for(int i = 1; i < 32; i++)
        dp[i][0] = 1, dp[i][i] = 1;
    for(int i = 2; i < 32; i++) {
        for(int j = 1; j < i; j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    //subsum[i][j] - subsum[i][j-1] = dp[i][j-1]
    for(int i = 1; i <= 32; i++) {
        for(int j = 1; j <= i+1; j++) {
            subsum[i][j] += dp[i][j-1] + subsum[i][j-1];
        }
    }

    // for(int i = 1; i < 32; i++) {
    //     for(int j = 0; j <= 32; j++) {
    //         cout << subsum[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}

void func(int idx, int bits, ll rest) {
    if(idx == n-1) {
        if(rest == 0) cout << "0";
        else cout << "1";
        return;
    }
    ll sub = subsum[n-1-idx][min(n-1-idx, bits)+1];
    // cout << n-1-idx << " " << rest << " " << bits << " " << sub << "\n";
    if(rest >= sub && bits > 0) {
        cout << "1";
        func(idx+1, bits-1, rest-sub);
    }
    else {
        cout << "0";
        func(idx+1, bits, rest);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> l >> k;
    init();
    func(0, l, k-1);
    // for(int i = 0; i < 100; i++) {
    //     func(0, l, i);
    //     cout << " " << i << "\n";
    // } 
}


/*
00000 0
00001 1
00010 2
00011 3 
00100 4
00101 5
00110 6
00111 7
01000 8
01001 9
01010 10
01011 11
01100 12
01101 13
01110 14
10000 15
10001 16
10010 17
10011 18
*/