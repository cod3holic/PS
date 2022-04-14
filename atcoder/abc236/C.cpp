#include <bits/stdc++.h>

using namespace std;

int n, m;

int main() {
    map<string, int> dict;
    vector<string> keys;
    cin >> n >> m;
    // cout << "?";
    keys.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> keys[i];
    }
    for (int i = 0; i < m; i++)
    {
        string str;
        cin >> str;
        dict[str] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        // cout << "?";
        cout << (dict.find(keys[i]) == dict.end() ? "No" : "Yes") << "\n";
    }
}