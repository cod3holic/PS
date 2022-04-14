#include<iostream>
#include<string>
#include<deque>

using namespace std;

int main() {
    string str, bomb;
    deque<char> dq;
    cin >> str;
    cin >> bomb;
    for(int i = 0; i < str.size(); i++) {
        char c = str[i];
        dq.push_back(c);
        if(c == bomb.back()) {
            bool flag = true;
            if(dq.size() >= bomb.size()) {
                for(int j = 1; j <= bomb.size(); j++) {
                    if(dq[dq.size()-j] != bomb[bomb.size()-j])
                        flag = false;
                }
            }
            else flag = false;

            if(flag) {
                int cnt = bomb.size();
                while(cnt--) dq.pop_back();
            }
        }
    }
    if(dq.empty()) cout << "FRULA";
    else
        for (auto &&item : dq)
            cout << item;
}