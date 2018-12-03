#include<bits/stdc++.h>
#define ll long long int
using namespace std;
//const int N=2e5;
//vector<int>g[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>A(n);
        for(int i=0;i<n;i++)
            cin>>A[i];
        ll storeSum[n];
        storeSum[0]=A[0];
        for(int i=1;i<n;i++)
            storeSum[i]=storeSum[i-1]+A[i];
        ll noPeople=0; //no. of people he can tell at particular day
//        ll rem=n-1;
        ll num=1,day=0;
        while(num<n)
        {
            day++;
            noPeople=storeSum[num-1];
            num+=noPeople;
        }
        cout<<day<<"\n";
    }
}

