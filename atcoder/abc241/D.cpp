#include <bits/stdc++.h>

using namespace std;

int q;
multiset<long long> A;

void query() {
    int a;
    long long b, c;
    cin >> a;
    if(a == 1) {
        cin >> b;
        A.insert(b);
    }
    else if(a == 2) {
        cin >> b >> c;
        auto iter = A.upper_bound(b);
        bool isneg = false;
        while(c--) {
            if(iter == A.begin()) {
                isneg = true;
                break;
            }
            iter--;
        }
        cout << (isneg ? -1 : *iter) << "\n";
        
    }
    else if(a == 3) {
        cin >> b >> c;
        auto iter = A.lower_bound(b);
        bool isneg = false;
        while(--c) {
            iter++;
            if(iter == A.end()) {
                isneg = true;
                break;
            }
        }
        cout << (isneg ? -1 : *iter) << "\n";
    }
}

int main() {
    cin >> q;
    while(q--) query();
}