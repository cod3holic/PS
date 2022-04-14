#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
int arr1[1000];
int arr2[1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    for (int i = 0; i < n; i++)
        cin >> arr2[i];
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr1[i] == arr2[i]) ans1++;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i == j) continue;
            if(arr1[i] == arr2[j]) {
                // cout << i << j << "\n";
                ans2++;
            }
        }
    }
    cout << ans1 << "\n" << ans2;
}