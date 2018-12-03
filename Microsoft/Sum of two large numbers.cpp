#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int t;
    cin>>t;
    while(t--)
    {
        long long int x,y,rem,cnts=0,n,cntx=0;
        cin>>x>>y;
         long long int sum;
        sum=x+y;
        n=sum;
        while(n>0)
        {
            rem=n%10;
            n=n/10;
            cnts++;
        }
        n=x;
        while(n>0)
        {
            rem=n%10;
            n=n/10;
            cntx++;
        }
        if(cnts==cntx)
            cout<<sum<<endl;
        else
            cout<<x<<endl;

    }
}
