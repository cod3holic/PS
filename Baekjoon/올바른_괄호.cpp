#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 2e9;
string str;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int l = 0, r = 0;
    cin >> str;
    for(auto c: str) {
        if(c == '(') l++;
        else r++; 
    }
    int sum = 0, cnt = 0;
    if(l > r) {
        for(auto i = str.begin(); i != str.end(); i++) {
            if(*i == '(') {
                sum += 1;
                cnt++;
            }
            else sum -= 1;
            if(sum == 0) {
                cnt = 0;
            }
        }
    }
    else {
        for(auto i = str.rbegin(); i != str.rend(); i++) {
            if(*i == ')') {
                sum += 1;
                cnt++;
            }
            else sum -= 1;
            if(sum == 0) {
                cnt = 0;
            }
        }
    }
    cout << cnt;
}