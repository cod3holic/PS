#include<iostream>

using namespace std;

int n, m;
bool isUsed[10];
int buf[10];

void func(int t, int k) {
    isUsed[t] = true;
    buf[k] = t;
    if(k == m) {
        for(int i = 1; i <= m; i++)
            cout << buf[i] << " ";
        cout << "\n";
        isUsed[t] = false;
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!isUsed[i]) func(i, k+1);
    }
    isUsed[t] = false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) func(i, 1);
}