#include<bits/stdc++.h>
using namespace std;
__int64 m=1002,o=1e9+7,n,r,s=0,i=1,j,p=1;
main(){
    vector<vector<int> >a(m,vector<int>(m));
    for(;i<m; i++)
        for(j=2,a[i][1]=1; j<=i; j++)
        (a[i][j]+=a[i-1][j]+a[i-1][j-1])%=o;
    cin>>n;
    for(i=0; i<n; i++) cin>>r,s+=r,(p*=a[s][r])%=o;
    cout<<p;
}
