#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    vector<pair<string,int>>v;
    for(int i = 0 ; i < s.size() ; i++){
        v.push_back({s.substr(i),i});
    }
    sort(v.begin(),v.end());
    for(auto x : v){
        cout << x.second << " ";
    }
    return 0;
}
