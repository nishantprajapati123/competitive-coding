#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mk make_pair
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define vi vector < int >
#define pii pair < int, int >
#define INF (int)1e9
#define fastIO ios::sync_with_stdio(0); cin.tie(0);
int main()
{
    fastIO
    int t;
    cin >> t;

    while(t--)
    {
        ll n,i,j;
        int a,b;
        cin>>n>>a>>b;
        vector<ll>A(n);
        for(ll k=0;k<n;k++)
            cin>>A[k];
        bool bob=true,alice=false;
        sort(A.begin(),A.end());
        i=n-1,j=n-1;
        while(true)
        {
            //bob turns
            while(bob)
            {
                if(A[i]!=0 && A[i]%a==0)
                {
                    A[i]=0;
                    bob=false,alice=true;
                }
                i--;
                if(i<0) break;
            }
            while(alice)
            {
            	if(a==b)
            	{
            		if(A[i]!=0 && A[i]%b==0)
                	{
                    	A[i]=0;
                    	bob=true,alice=false;
                	}
            	}
            	else
            	{
                	if(A[j]!=0 && A[j]%b==0)
                	{
                    	A[j]=0;
                    	bob=true,alice=false;
                	}
                }
                j--;
                if(j<0) break;
            }
            if(i<0 || j<0) break;
        }
        if(i<0)
            cout<<"ALICE"<<"\n";
        else if(j<0)
            cout<<"BOB"<<"\n";
    }
    return 0;
}
