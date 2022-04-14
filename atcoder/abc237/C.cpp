#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    cin >> str;


    auto iter2 = str.rbegin();
    while(iter2 != str.rend()) {
        if(*iter2!='a') break;
        iter2++;
    }
    int offset = iter2 - str.rbegin();
    str = str.substr(0, str.rend() - iter2);
    
    auto iter1 = str.begin();
    while(iter1 != str.end()) {
        if(iter1 - str.begin() >= offset) break;
        if(*iter1!='a') break;
        iter1++;
    }
    str = str.substr(iter1-str.begin());

    int l = 0, r = str.size()-1;
    while (l <= r) {
        // cout << str[l] << " " << str[r] << "\n";
        if(str[l] != str[r]) {
            cout << "No";
            return 0;
        }
        l++, r--;
    }
    cout << "Yes";
    return 0;
}