#include <bits/stdc++.h>
using namespace std;

int maximum_sum(vector<int> & a){
    int l=0;
    int sum=0;
    int ans=INT_MIN;

    while(l<a.size()){
        sum+=a[l];
        ans=max(ans,sum);
        if(sum<0)
            sum=0;
        l++;
    }
    return ans;
}

int main() {
    vector<int> a={-2,-5,6,-2,-3,1,5,-6};
    int ans=maximum_sum(a);
    cout<<ans;
    return 0;
}

