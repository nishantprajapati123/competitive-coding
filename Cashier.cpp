#include<bits/stdc++.h>
#define fo(i,n) for(int i=0;i<n;i++)
using namespace std;
int main()
{
    int n;
    long L,a;
    long freetime=0;
    cin>>n>>L>>a;
    int cash[n][2];
    int res=0;
    fo(i,n)
    {
        int t,l;
        cin>>t>>l;
        cash[i][0]=t;
        cash[i][1]=l;
    }
    int tilldone=0;
    fo(i,n)
    {
        if((cash[i][0]-tilldone)>=a)
            res+=(cash[i][0]-tilldone)/a;
        //coustmer will consume
        tilldone+=(cash[i][0]-tilldone)+cash[i][1];

    }
    if(L-tilldone >=a)
        res+=(L-tilldone)/a;
    cout<<res;
}
