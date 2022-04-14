#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    cin >> n;
    list<int> arr;
    arr.push_back(0);
    auto cur = arr.begin();
    int idx = 0;
    while(n--) {
        char cmd;
        cin >> cmd;
        if(cmd == 'L') {
            arr.insert(cur, ++idx);
            cur--;
        }
        else if(cmd == 'R') {
            arr.insert(++cur, ++idx);
            cur--;
        }
        // cout << *cur << "/" << cmd << "/";
        // for (auto &&item : arr)
        // {
        //     cout << item << " ";
        // }
        // cout << "\n";
    }
    for (auto &&item : arr)
    {
        cout << item << " ";
    }
}