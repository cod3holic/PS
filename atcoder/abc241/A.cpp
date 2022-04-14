#include <bits/stdc++.h>

using namespace std;

int arr[10];

int main() {
    for (int i = 0; i < 10; i++)
        cin >> arr[i];
    int t = 0;
    for (int i = 0; i < 3; i++)
        t = arr[t];
    cout << t;
}