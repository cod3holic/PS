#include<iostream>
#include<algorithm>

using namespace std;
int n, m;
int arr[100000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);
    cin >> m;
    while(m--) {
        int k;
        cin >> k;
        cout << binary_search(arr, arr+n, k) << "\n";
    }
}