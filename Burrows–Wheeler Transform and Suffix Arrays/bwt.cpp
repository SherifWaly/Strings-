#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    vector<string>v;
    for(int i = 0 ; i < s.size() ; i++){
        v.push_back(s.substr(i) + s.substr(0,i));
    }
    sort(v.begin(),v.end());
    string ans = "";
    for(int i = 0 ; i < v.size() ; i++){
        ans += v[i].back();
    }
    cout << ans;
    return 0;
}
