#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n, k;
        cin>>n>>k;
        vector<ll>A(n);
        for(ll i=0;i<n;i++) cin>>A[i];
        ll i=0,j=0;
        ll sum = A[i];
        bool found = false;
        if(sum == k)
            found = true;
        else
        {
            for(j=1;j<n;j++)
            {
                sum += A[j];
                while(sum > k && i<=j)
                {
                    sum -= A[i];
                    i++;

                    cout<<i<<endl;
                }
                if(sum == k)
                   { found = true; break;}
//                cout<<i<<" "<<j<<" "<<sum<<endl;
            }
        }
         if(found)   cout<<i+1<<" "<<j+1<<"\n";
         else    cout<<"-1\n";

    }
    return 0;
}
