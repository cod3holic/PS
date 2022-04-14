#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int n;
bool arr[26][26];
bool visited[26][26];
vector<int> ans;

bool isvalid(int a, int b) {
    if(a < 0 || a >= n) return false;
    if(b < 0 || b >= n) return false;
    return true;
}

int func(int a, int b) {
    visited[a][b] = true;
    int ret = 1;
    for(int i = 0; i < 4; i++) {
        int na = a+dy[i], nb = b+dx[i];
        if(!visited[na][nb] && arr[na][nb])
            ret += func(na, nb);
    }
    return ret;

}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < n; j++)
            arr[i][j] = str[j] - '0';
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i][j] && !visited[i][j])
                ans.push_back(func(i, j));
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(auto&& item: ans) {
        cout << item << "\n";
    }
}