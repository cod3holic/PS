// 백트래킹으로 다시 풀어보자.

#include <bits/stdc++.h>

using namespace std;

int n;
int arr[16][16];
bool used[20];
vector<pair<int, int>> logs;

int func(int cnt) {
    int ret = 0;
    if(cnt == n) {
        for (auto &&item : logs)
            ret ^= arr[item.first][item.second];    
        return ret;
    }
    int a = 0;
    while(used[a]) a++;
    used[a] = true;
    for (int b = a+1; b < 2*n; b++) {
        if(used[b]) continue;
        used[b] = true;
        logs.push_back({a, b});
        ret = max(ret, func(cnt+1));
        used[b] = false;
        logs.pop_back();
    }
    used[a] = false;
    return ret;
}

int main() {
    cin >> n;
    for (int i = 0; i < 2*n-1; i++)
    {
        for (int j = i+1; j < 2*n; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << func(0);
}