#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    vector<int> v;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    cout << (unique(v.begin(), v.end()) - v.begin());
}