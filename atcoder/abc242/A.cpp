#include <bits/stdc++.h>

using namespace std;

int a, b, c, x;

int main() {
    cin >> a >> b >> c >> x;
    cout.precision(11);
    if(x <= a) cout << 1.0f;
    else if(b < x) cout << 0.0f;
    else cout << (double)(c)/(b-a);
}