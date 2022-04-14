#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    int a, b;
    cin >> str;
    cin >> a >> b;
    swap(str[a-1], str[b-1]);
    cout << str;
}