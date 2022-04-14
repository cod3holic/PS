#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int n, k;
int arr[100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;

    set<int> plug;
    
    for (int i = 0; i < k; i++)
        cin >> arr[i];
    int ans = 0;
    for (int i = 0; i < k; i++) {
        if(plug.find(arr[i]) != plug.end()) continue;
        if(plug.size() < n) {
            plug.insert(arr[i]);
            continue;
        }
        int m = -1, val = -1;
        for (auto &&item : plug)
        {
            int first = 2e9;
            for (int j = i+1; j < k; j++) {
                if(arr[j] == item) {
                    first = j;
                    break;
                }
            }
            if(first > m) {
                m = first;
                val = item;
            }
        }
        ans++;
        plug.erase(val);
        plug.insert(arr[i]);
    }
    cout << ans;
}

/*
2 3 2 3 1 2 7
2 3

*/