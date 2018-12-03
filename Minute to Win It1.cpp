#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int a[n],cntr=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int i=1;
    while(i<n-1)
    {
        if((a[i]-a[i-1])!=k && (a[i+1]-a[i])!=k && (a[i+1]-a[i-1])==2*k)
        {
            a[i]=a[i-1]+k;
            cntr++;
        }
        i++;
    }
    int z=0;
    for(int i=1;i<n;i++)
    {
        if((a[i]-a[i-1])!=k)
            z++;
    }
    cout<<cntr+z<<endl;

}


