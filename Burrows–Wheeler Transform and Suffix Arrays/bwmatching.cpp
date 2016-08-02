#include <bits/stdc++.h>
using namespace std;
map<char,int>cnt[1000005];
map<char,int>firstOcc;
string text;
int solve(){
    string s;
    cin >> s;
    int top = 0, bottom = text.size()-1;
    int idx = s.size()-1;
    while(top <= bottom){
        if(idx >= 0){
            if(cnt[bottom+1][s[idx]]-cnt[top][s[idx]]){
                top = firstOcc[s[idx]] + cnt[top][s[idx]];
                bottom = firstOcc[s[idx]] + cnt[bottom+1][s[idx]] - 1;
            }
            else return 0;
            idx--;
        }
        else{
            return bottom-top+1;
        }
    }
    return bottom-top+1;
}
int main() {
    cin.tie(0);
    cin >> text;
    string x = text;
    sort(x.begin(),x.end());
    for(int i = 0 ; i < x.size() ; i++){
        if(firstOcc.find(x[i]) == firstOcc.end()){
            firstOcc[x[i]] = i;
        }
    }
    for(int i = 0 ; i < text.size() ; i++){
        for(auto x : firstOcc){
            cnt[i+1][x.first] = cnt[i][x.first];
        }
        cnt[i+1][text[i]]++;
    }
    int n;
    scanf("%d",&n);
    while(n--){
        printf("%d ",solve());
    }
    return 0;
}
