#include <bits/stdc++.h>

using namespace std;

int r, c;
int arr[20][20];
bool vec[26];
int sign[2] = {-1, 1};
int m;

bool isvalid(int a, int b) {
    if(a < 0 || a >= r) return false;
    if(b < 0 || b >= c) return false;
    return true;
}

void func(int a, int b, int cnt) {
    int& t = arr[a][b];
    if(vec[t]) {
        m = max(m, cnt);
        return;
    }
    cnt++;
    vec[t] = true;
    int m = 0;
    for (int i = 0; i < 2; i++)
    {
        for (auto &&s : sign)
        {
            int nxt[2] = {a, b};
            nxt[i] += s;
            if(!isvalid(nxt[0], nxt[1])) continue;
            func(nxt[0], nxt[1], cnt);
        }
    }
    vec[t] = false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            char t;
            cin >> t;
            arr[i][j] = t-'A';
        }
    func(0, 0, 0);
    cout << m;
}