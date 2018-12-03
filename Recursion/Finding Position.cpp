#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long n;
        cin>>n;
        cout<<pow(2,(int)(log(n)/log(2)))<<endl;
    }
}
