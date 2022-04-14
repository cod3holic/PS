#include <bits/stdc++.h>

using namespace std;

long long n;

int main() {
    cin >> n;
    cout << ((n <= (1ll<<31)-1 && n >= (-2147483648)) ? "Yes" : "No");
}