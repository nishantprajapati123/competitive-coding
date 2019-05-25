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
  //  freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    vector<ll>A(n);
    for(int i=0;i<n;i++)    cin>>A[i];
    int i=0,j=n-1;
    while(i<j)
    {
        //cout<<"ok"<<endl;
        if(!(A[i]&1) && (A[j]&1))   i++,j--;
        else if((A[i]&1) && !(A[j]&1))  swap(A[i],A[j]), i++,j--;
        else if(!(A[i]&1) && !(A[j]&1)) i++, swap(A[i],A[j]);
        else if((A[i]&1) && (A[j]&1))   j--,swap(A[i],A[j]);
    }
    int even_it;
    if(!(A[0]&1))
    {
        for(even_it=0;!(A[even_it]&1) && even_it<n ;even_it++);
//        cout<<endl<<even_it<<endl;
        sort(A.begin(),A.begin()+even_it);
        sort(A.begin()+even_it,A.end(),greater<ll>());
    }
    else
    {
        even_it=-1;
        sort(A.begin(),A.end(),greater<ll>());
    }
    int even_no,odd_no,t;
    if(even_it==-1) even_no = 0, odd_no=n;
    else    even_no = even_it, odd_no = n-even_it;
 //   cout<<even_it<<" "<<even_no<<" "<<odd_no<<"\n";
    if((even_no==odd_no) || abs(even_no-odd_no)==1) cout<<"0\n";
    else if(even_no>odd_no)
    {
        t = even_no-odd_no-1,i=0;
        ll res= accumulate(A.begin(),A.begin()+t,0);
        cout<<res<<"\n";
    }
    else
    {
        t = odd_no-even_no-1,i=n-1;
        ll res = 0;
        while(t--)
        {
            res+=A[i];
            i--;
        }
        cout<<res<<"\n";
    }
   // for(auto x:A)   cout<<x<<" ";
    return 0;
}
