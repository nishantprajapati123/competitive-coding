#include<bits/stdc++.h>
using namespace std;
long int howManyGoodSubarrays(vector<long int>a, int n, int m, int k)
{
    long long int mult,cont=0;
    for(int i=0;i<n;i++)
    {
        mult=1;
        for(int j=i;j<n;j++)
        {
            mult=((mult%m)*(a[j]%m))%m;
            if(mult%m==k)
                cont++;
        }
    }
    return cont;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long int m;
        int n,k;
        cin>>n>>m>>k;
        vector<long int>a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        cout<<howManyGoodSubarrays(a,n,m,k)<<endl;
    }
}
