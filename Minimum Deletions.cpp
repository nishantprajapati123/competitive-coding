#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long int result;
        int n;
        cin>>n;
        vector<long int>arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        result=arr[0];
        for(int i=1;i<n;i++)
        {
            result=__gcd(arr[i],result);
        }
        if(result==1)
            cout<<"0"<<endl;
        else
            cout<<"-1"<<endl;
    }
}
