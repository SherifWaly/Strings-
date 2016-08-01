#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
map<pair<int,char>,int>mp;
map<char,int>occ1, occ2;
int place2[2000001];
int main() {
    string b;
    cin >> b;
    string a = b;
    sort(a.begin(),a.end());
    for(int i = 0 ; i < a.size() ; i++){
        int x = ++occ1[a[i]];
        mp[{x,a[i]}] = i;
    }
    for(int i = 0 ; i < b.size() ; i++){
        place2[i] = mp[{++occ2[b[i]],b[i]}];
    }
    string ans = "";
    int x = 0;
    while(true){
        ans += a[x];
        if(ans.size() == a.size()){
            break;
        }
        x = place2[x];
    }
    cout << string(ans.rbegin(),ans.rend());
    return 0;
}
