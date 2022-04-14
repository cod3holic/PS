#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
int arr[1000000];
bool inMyView[1000000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
        cin >> inMyView[i];
    
    ll all = 0, sub = 0;
    for (int i = 0; i < n; i++)
    {
        if(!inMyView[i]) sub += arr[i];
        all += arr[i];
    }
    cout << all << "\n" << sub;
}