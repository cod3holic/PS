/**
 * tarjan 알고리즘의 변형으로 단절점 찾기
 * https://www.crocus.co.kr/1164
 * https://justicehui.github.io/hard-algorithm/2019/01/06/ArticulationPoint/
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> E[10001];
int dfsn[10001];
int v, e, dfs_cnt, cutv_cnt;
bool iscut[10001];

int dfs(int k, int par) {
    int ret = dfsn[k] = ++dfs_cnt;
    int sub = 0;
    for (auto next : E[k])
    {
        if(next == par) continue;
        if(dfsn[next]) ret = min(dfsn[next], ret);
        else {
            sub++;
            int m = dfs(next, k);
            if(par != 0 && m >= dfsn[k]) {
                iscut[k] = true;
            }
            ret = min(ret, m);
        }
    }
    if(par == 0 && sub > 1) {
        // 예외사항: 루트는 2개의 자식이 있다면 단절점이다.
        iscut[k] = true;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> v >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    for (int i = 1; i <= v; i++)
        if(!dfsn[i]) dfs(i, 0);
    
    for (int i = 1; i <= v; i++)
        cutv_cnt += iscut[i];
    cout << cutv_cnt << "\n";
    for (int i = 1; i <= v; i++)
        if (iscut[i]) cout << i << " ";
}