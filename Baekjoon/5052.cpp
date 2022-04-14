#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int trie[100101][10];
bool isend[100101];
int idx;

bool insert(string str) {
    int node = 0;
    bool flag = true;
    for(auto c: str) {
        c = c-'0';
        if(trie[node][c] == -1) {
            trie[node][c] = ++idx;
            node = idx;
        }
        else {
            node = trie[node][c];
            if(isend[node]) flag = false;
        }
    }
    isend[node] = true;
    for(int i = 0; i < 10; i++) {
        if(trie[node][i] != -1) flag = false;
    }
    return flag;
}

void sovle() {
    fill(trie[0], trie[0]+100101*10, -1);
    fill(isend, isend+100101, false);
    idx = 0;
    int n;
    cin >> n;
    bool flag = true;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if(!insert(str)) {
            flag = false;
        }
    }
    if(flag) cout << "YES\n";
    else cout << "NO\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) sovle();
}