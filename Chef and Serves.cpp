#include<bits/stdc++.h>
#define ll long long
#define fo(i,n) for(int i=0;i<n;i++)
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int p1,p2,k;
        cin>>p1>>p2>>k;
        int totpoint=p1+p2;
        int turn=totpoint/k;
        if(turn%2==0)
            cout<<"CHEF"<<"\n";
        else
            cout<<"COOK"<<"\n";
    }
}
