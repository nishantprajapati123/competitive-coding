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
void addOpen(string &A, int x)
{
    while(x--)
    {
        A += '(';
    }
}
void addClose(string &B, int x)
{
    while(x--)
    {
        B += ')';
    }
}
string nested(string s)
{
    int n = s.length();

    string res = "";
    int diff = s[0] - '0';

    //at beginning
    addOpen(res,diff);

    for(int i=0;i<n-1;i++)
    {
        res += s[i];
        diff = (s[i] - '0') - (s[i+1] - '0');

        if(diff>=0)
            addClose(res,diff);
        else
            addOpen(res,abs(diff));
    }

    //at end
    res += s[n -1];
    diff = s[n-1] - '0';
    addClose(res,diff);

    return res;
}
int main()
{
    fastIO
    int nooftestcase;
    cin>>nooftestcase;
    cin.ignore();
    for(int testcase = 1;testcase<=nooftestcase;testcase++)
    {
        string S;
        getline(cin,S);

        cout<<"Case #"<<testcase<<": "<<nested(S)<<"\n";
    }
    return 0;
}
