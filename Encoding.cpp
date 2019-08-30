#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int cal(long long int x)
{
    char tmp = '/';
    string s = to_string(x);
    vector<pair<int, int > >res;
    for(int i=0;i<s.length();i++)
    {
        if(s[i] != tmp)
        {
            int tmp1 = s.length()-i-1;
            int tmp2 = s[i]-'0';
            res.push_back({tmp1,tmp2});
            tmp = s[i];
        }
    }
    int ans = 0;
    for(auto itr:res)
    {
        long long int tmp3= ((itr.second*(long long int)pow(10, itr.first))%MOD);
        ans = (ans+ tmp3)%MOD;
    }
    return ans;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int Nl,Nr;
        long long int L,R;
        cin>>Nl>>L;
        cin>>Nr>>R;

        int res = 0;
        for(long long int i=L;i<=R;i++)
        {
            res = (res + cal(i))%MOD;
        }
        cout<<res<<"\n";
    }

}
