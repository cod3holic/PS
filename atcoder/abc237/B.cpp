#include <bits/stdc++.h>

using namespace std;

int h, w;
vector<vector<int>> arr;

int main() {
    cin >> h >> w;
    arr.resize(h);
    for (int i = 0; i < h; i++)
        arr[i].resize(w);
    
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> arr[i][j];
    
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++)
            cout << arr[j][i] << " ";
        cout << "\n";
    }
    
}