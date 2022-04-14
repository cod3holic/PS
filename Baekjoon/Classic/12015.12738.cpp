/**
 * 21.12.05
 * LIS O(nlogn)
 */

#include <bits/stdc++.h>
#define MAX 1000000

using namespace std;

int subsq[MAX];
int l = 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    cin >> subsq[0];
    for (int i = 0; i < n-1; i++)
    {
        int now;
        cin >> now;
        int* k = lower_bound(subsq, subsq+l, now);
        *k = now;
        if(k-subsq == l) l++;
    }
    cout << l;
}