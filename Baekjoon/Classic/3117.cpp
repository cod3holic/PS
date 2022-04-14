#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int table[100001][31];
int arr[100001];
// log_10(100001)/log_10(2) ~= 30

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= k; i++)
        cin >> table[i][0];
    
    for (int i = 1; i < 31; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            int half = table[j][i-1];
            table[j][i] = table[half][i-1];
        }
    }

    m--;
    for (int i = 0; i < 31; i++)
    {
        if(m & (1 << i)) {
            for (int j = 1; j <= n; j++)
            {
                arr[j] = table[arr[j]][i];
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    
}