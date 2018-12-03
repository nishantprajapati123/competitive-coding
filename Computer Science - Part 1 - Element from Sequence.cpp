#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
using namespace std;
template<typename T>
int pop_front(std::vector<T>& vec)
{
    assert(!vec.empty());
   return vec.erase(vec.begin());
}
vector<ll> permutaion(vector<ll>a)
{
    bool done=false;
    vector<ll>b=a;
    if(next_permutation(b.begin(),b.end()))
    {
        done=true;
    }
    if(!done)
    {
        b=a;
        prev_permutation(b.begin(),b.end());
    }
    return b;

}
int main()
{
    fastIO;
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    int q;
    cin>>q;
    while(q--)
    {
        vector<ll>temp;
        int x,l,r;
        cin>>x>>l>>r;
        if(x==1)
        {
            int p=0;
            for(int i=l-1;i<r;i++)
                temp.pb(a[i]);
            temp=permutaion(temp);
            for(int i=l-1;i<r;i++)
                a[i]=temp[p++];
            cout<<"ok";
        }
       else if(x==2)
        {
            ll mean=accumulate(a.begin()+l-1,a.begin()+r,0)/(r-l+1);
            mean=mean%mod;
            cout<<mean;

        }
//        for(int i=0;i<n;i++)
//            cout<<a[i]<<" ";
    }
}
