#include <bits/stdc++.h>

using namespace std;

const int dx[8] = {0, 0, -1, 1, -1, 1, -1, 1};
const int dy[8] = {-1, 1, 0, 0, -1, 1, 1, -1};

int n;
int arr[1000][1000];
bool visited[1000][1000];

bool isvalid(int a, int b) {
    if(a < 0 || a >= n) return false;
    if(b < 0 || b >= n) return false;
    return true;
}

int func(int a, int b, int rest, int dir) {
    if(rest < 0) return 0;
    int na = a+dy[dir], nb = b+dx[dir];
    int ret = 1;
    if(isvalid(na, nb)) {
        if(arr[na][nb] == '.') {
            ret += func(na, nb, rest-1, dir);
        }
        else if(arr[na][nb] == '#') {
            ret += func(na, nb, rest, dir);
        }
    }
    return ret;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++)
            arr[i][j] = str[j];
    }
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
        {
            if(arr[i][j] == '#') {
                int cnt = 0;
                for (int k = 0; k <= 2; k++) {
                    cnt = max(cnt, func(i, j, k, 0) + func(i, j, 2-k, 1) -1);
                    cnt = max(cnt, func(i, j, k, 2) + func(i, j, 2-k, 3) -1);
                    cnt = max(cnt, func(i, j, k, 4) + func(i, j, 2-k, 5) -1);
                    cnt = max(cnt, func(i, j, k, 6) + func(i, j, 2-k, 7) -1);
                }
                if(cnt >= 6) {
                    cout << "Yes";
                    return 0;
                }
            }
        }
    }
    cout << "No";
}