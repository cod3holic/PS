#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
int arr[16][16];
int dp[100000];

int search(int pairs) {
    if(pairs == 0) return 0;
    // int& ret = dp[pairs];
    // if(ret != -1) return ret;
    // ret = 0;
    int ret = 0;
    // cout << pairs << "\n";
    for (int i = 0; i < 2*n-1; i++)
    {
        for (int j = i+1; j < 2*n; j++)
        {
            if(((1 << i) & pairs) && ((1 << j) & pairs)) {
                int comb = pairs - (1 << i) - (1 << j);
                ret = max(ret, arr[i][j]^search(comb));
            }
        }
    }
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
    fill(dp, dp+100000, -1);

    // for (int i = 0; i < 2*n-1; i++)
    // {
    //     for (int j = i+1; j < 2*n; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << search((1<<(2*n))-1);
}