#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,W;
    cin>>n;
    vector<int> v(n), w(n);
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<n;i++) cin>>w[i];
    cin>>W;

    vector<int> idx(n);
    iota(idx.begin(),idx.end(),0);
    sort(idx.begin(),idx.end(),[&](int a,int b){
        return (double)v[a]/w[a] > (double)v[b]/w[b];
    });

    double ans=0;
    for(int i:idx){
        if(W>=w[i]) ans+=v[i], W-=w[i];
        else{ ans+= (double)v[i]*W/w[i]; break; }
    }

    cout<<(int)ans;
}
