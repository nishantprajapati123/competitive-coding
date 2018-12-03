#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll sequence(int cal ,int current, int n)
{
    ll cur=1,i;
    if(current==n+1)
        return 0;
    for(i=cal;i<cal+current;i++)
        cur*=i;
    //cout<<cur<<endl;
    return cur+sequence(i,current+1,n);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<sequence(1,1,n)<<endl;
    }
}
