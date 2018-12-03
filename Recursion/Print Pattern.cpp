#include<bits/stdc++.h>
using namespace std;
void forNegative(int n, int num)
{
    if(n>num)
        return;
    cout<<n<<" ";
    forNegative(n+5,num);
}
void forPositive(int n, int num)
{
    if(n>0)
    {
        cout<<n<<" ";
        forPositive(n-5,num);
    }
    else
    {
        forNegative(n,num);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int num=n;
        forPositive(n,num);
    }
}
