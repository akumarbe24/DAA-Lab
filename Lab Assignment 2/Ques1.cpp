#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++) cin>>a[i].first;
    for(int i=0;i<n;i++) cin>>a[i].second;

    vector<pair<int,int>> v;
    for(int i=0;i<n;i++) v.push_back({a[i].second,a[i].first});
    sort(v.begin(),v.end());

    int cnt=0,last=-1;
    vector<pair<int,int>> res;
    for(auto &p:v){
        if(p.second>=last){
            cnt++;
            res.push_back({p.second,p.first});
            last=p.first;
        }
    }

    cout<<cnt<<"\n";
    for(auto &p:res) cout<<"("<<p.first<<","<<p.second<<") ";
}
