#include<bits/stdc++.h>
using namespace std;
int main()
{
    int s,n,m,result=-1,key[1001],usb[1001];
    cin>>s>>n>>m;
    int i,j;
    for(i=0;i<n;i++)
        cin>>key[i];
    for(j=0;j<m;j++)
        cin>>usb[j];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(key[i]+usb[j]<=s)
                result=max(result,key[i]+usb[j]);
        }
    }
    cout<<result;
}
