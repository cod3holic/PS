#include <bits/stdc++.h>

using namespace std;

bool sieve[301];
int a, b, c, d;

void init(){
    fill(sieve, sieve+301, true);
    sieve[0]=sieve[1]=false; 
    for(int i = 2; i <= 300; i++) {
        if(sieve[i]) {
            for(int j = 2*i; j <= 300; j+=i)
                sieve[j] = false;
        }
    }
}

int main() {
    cin >> a >> b;
    cin >> c >> d;
    init();
    
    // for (int i = 0; i < 100; i++)
    // {
    //     if(sieve[i]) cout << i;
    // }
    
    bool takawin = false;
    for(int i = a; i <= b; i++) {
        bool makeprime = false;
        for(int j = c; j <= d; j++) {
            if(sieve[i+j]) {
                makeprime = true;
            }
        }
        if(!makeprime) {
            takawin = true;
            break;
        }
    }
    if(takawin) cout << "Takahashi";
    else cout << "Aoki";
}