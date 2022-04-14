#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    a -= 1, b -= 1;
    if((a+1)%10 == b || a == (b+1)%10) cout << "Yes";
    else cout << "No";
}