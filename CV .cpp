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
    freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cin.ignore();
        string s;
        getline(cin,s);
        int i=0,cnt=0;
        while(i<n-1)
        {
            if((s[i]!='a' && s[i]!='e' && s[i]!='o' && s[i]!='i' && s[i]!='u') && (s[i+1]=='a'||s[i+1]=='e'||s[i+1]=='i'||s[i+1]=='o'||s[i+1]=='u'))
                cnt++,i+=2;
            else
                i++;
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
