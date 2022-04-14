// d = t * t * ... * alpha 

#include <bits/stdc++.h>

using namespace std;

int t, n, d;
int map[101][20][20];
int batch[20][20];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t >> n >> d;

    fill(map[0][0], map[0][0]*101*20*20, 0);

    for (int i = 0; i < t; i++)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int a, b, c;
            cin >> a >> b >> c;
            map[i][a][b] = c;
        }
    }
    
}