#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int>a(n);
    for (int i = 0; i <n; i++)
    {
        cin>>a[i];
    }
    int s;cin>>s;
    int i = 0, j = 0,sum = 0;
    int mx = 0;
    map<int,int>mp;
    for (int i = 0; i < n; i++)
    {
        sum+=a[i];
        if (sum == s)
        {
            // cout<<i+1<<endl;
            //when we get it in early
            mx= max(mx,i+1);
        }
        if (sum>s)
        {
           if (mp.find(sum-s)!= mp.end())
           {
            // when we get it after move forward
            //  cout<<i-mp[sum-s]<<endl;
             mx = max(mx, i-mp[sum-s]);
           }
           if (mp.find(sum-s) == mp.end())
           {
            // we only push sum value when this sum is not available in the map
             // it's help us to ignore the multiple same sum.
             mp[sum]=i;
           }
           
        } 
    }
    cout<<mx<<endl; 
    return 0;
}