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
    int ticketcost,avaseat,t,newcost,x;
    cin>>ticketcost>>avaseat>>t>>newcost>>x;
    int totalcost=0,i;
    for(i=1;i<=x;i++)
    {
        if(avaseat>t)
            avaseat--;
        else
            break;
    }
    i--;
    totalcost=(ticketcost*i)+(newcost*(x-i));
    cout<<totalcost;

}
