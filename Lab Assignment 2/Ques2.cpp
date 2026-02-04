#include <bits/stdc++.h>
using namespace std;

int toMin(string s){
    return stoi(s.substr(0,2))*60 + stoi(s.substr(3,2));
}

int main(){
    int n;
    cin>>n;
    vector<string> a(n), d(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>d[i];

    vector<int> at(n), dt(n);
    for(int i=0;i<n;i++) at[i]=toMin(a[i]), dt[i]=toMin(d[i]);

    sort(at.begin(),at.end());
    sort(dt.begin(),dt.end());

    int i=0,j=0,cur=0,ans=0;
    while(i<n){
        if(at[i]<=dt[j]){
            cur++; ans=max(ans,cur); i++;
        }else{
            cur--; j++;
        }
    }

    cout<<ans;
}
