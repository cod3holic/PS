#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
int arr[100000][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

    int maxbuf[3] = {arr[0][0], arr[0][1], arr[0][2]};
    int minbuf[3] = {arr[0][0], arr[0][1], arr[0][2]};
    int tmp[3] = {0};
    for (int i = 1; i < n; i++)
    {
        tmp[0] = max(maxbuf[0], maxbuf[1]) + arr[i][0];
        tmp[1] = max(maxbuf[0], max(maxbuf[1], maxbuf[2])) + arr[i][1];
        tmp[2] = max(maxbuf[1], maxbuf[2]) + arr[i][2];
        maxbuf[0] = tmp[0], maxbuf[1] = tmp[1], maxbuf[2] = tmp[2];

        tmp[0] = min(minbuf[0], minbuf[1]) + arr[i][0];
        tmp[1] = min(minbuf[0], min(minbuf[1], minbuf[2])) + arr[i][1];
        tmp[2] = min(minbuf[1], minbuf[2]) + arr[i][2];
        minbuf[0] = tmp[0], minbuf[1] = tmp[1], minbuf[2] = tmp[2];
    
        // cout << maxbuf[0] << " " << maxbuf[1] << " " << maxbuf[2] << "\n";
        
    }
    cout << *max_element(maxbuf, maxbuf+3) << " " << *min_element(minbuf, minbuf+3);
}