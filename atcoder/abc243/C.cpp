#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
set<int> ys;
map<int, vector<pair<int, int>>> pos;
int arr1[200000];
int arr2[200000];
int arr3[200000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        arr1[i] = x, arr2[i] = y;
    }
    string str;
    cin >> str;
    for (int i = 0; i < n; i++)
        arr3[i] = (str[i] == 'L' ? -1 : 1);
    
    for (int i = 0; i < n; i++)
    {
        ys.insert(arr2[i]);
        pos[arr2[i]].push_back({arr1[i], arr3[i]});
    }
    
    for (auto &&y : ys)
    {
        sort(pos[y].begin(), pos[y].end());
        bool facing = false;
        for (auto &&item : pos[y])
        {
            int x, f;
            tie(x, f) = item;
            if(facing) {
                if(f == 1) continue;
                cout << "Yes";
                return 0;
            }
            if(f == 1) facing = true;
        }        
    }
    cout << "No";
}