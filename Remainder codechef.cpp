#include<bits/stdc++.h>
typedef long long ll;
typedef long l;
#define modu 1000000007
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll N,rem;
        l M;
        cin>>N>>M;
        rem=N%M;
        if(rem%2==0)
            cout<<"EVEN";
        else
            cout<<"ODD";
    }
}
