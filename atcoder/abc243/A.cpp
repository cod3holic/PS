#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int v, a, b, c;

int main() {
    cin >> v >> a >> b >> c;
    int i = 2;
    while(v >= 0)
    {
        i=(i+1)%3;
        if(i == 0) v-=a;
        else if(i == 1) v-=b;
        else if(i == 2) v-=c;
    }
    if(i == 0) cout << "F";
    else if(i == 1) cout << "M";
    else if(i == 2) cout << "T";
        
}