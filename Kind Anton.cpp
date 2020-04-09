#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mk make_pair
#define deb(x) cout << #x << "=" << x << endl
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define MOD 1000000007
#define INF (int)1e9
#define fastIO ios::sync_with_stdio(0); cin.tie(0);
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
string solve()
{
    int n;
    scanf("%d",&n);
    vi A(n), B(n);
    for(int &x:A)
        scanf("%d",&x);

    for(int &x:B)
        scanf("%d",&x);
    
    if(A[0]!=B[0])
        return "NO";
    
    // for(int i=0;i<n;i++)
    // {
    //     if(A[i] == B[i])    continue;


    // }
    int i_pos = INT_MAX, i_neg = INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(A[i]>0)
        {  
            i_pos = i; break;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(A[i]<0)
        {  
            i_neg = i; break;
        }
    }
    

    for(int i=n-1;i>=0;i--)
    {
        if(B[i] == A[i])    continue;
        if(B[i] > 0)
        {
            if(A[i] < 0 && i_pos >= i)   return "NO";
            if(A[i] == 0 && i_pos >= i)  return "NO";
            if(A[i] > 0 && i_pos >= i)  return "NO";
        }
        else if(B[i] < 0)
        {
            if(A[i] < 0 && i_neg >= i)   return "NO";
            if(A[i] == 0 && i_neg >= i)  return "NO";
            if(A[i] > 0 && i_neg >= i)   return "NO";
        }
        else
        {
            if(A[i] < 0 && i_pos >= i)   return "NO";
            if(A[i] > 0 && i_neg >= i)   return "NO";
        }
        
    }
    return "YES";
}
int main()
{
    fastIO
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase<=T; testcase++)
    {
        string ans = solve();
        cout<<ans<<"\n";
        // printf("\n");
    }
    return 0;
}