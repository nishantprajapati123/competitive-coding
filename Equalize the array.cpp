#include<bits/stdc++.h>
using namespace std;
int fre[101]={0};
int main()
{
    int n, a,m=0,pos,result=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        fre[a]+=1;
        if(fre[a]>m)
        {
            m=fre[a];
            pos=a;
        }
    }
    for(int i=0;i<101;i++)
    {
        if(i!=pos)
            result+=fre[i];
    }
    cout<<result<<endl;
}
