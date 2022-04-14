#include<iostream>
#include<vector>

using namespace std;
vector<string> words;

int main() {
    int n, q;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        words.push_back(s);
    }
    cin >> q;
    while(q--) {
        string s;
        cin >> s;
        for (auto &&str : words)
        {
            if(str.substr(0, s.size()) == s) {
                cout << str << "\n";
            }
        }
    }
}