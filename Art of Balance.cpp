#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mk make_pair
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define vi vector < int >
#define pii pair < int, int >
#define INF (int)1e9
#define fastIO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
vector<ll> getDivisor(ll len)
{
    vector<ll>div;
    for(ll i=1;i*i<=len;i++)
    {
        if(len%i==0)
        {
            div.pb(i);
            if(i!=len/i)
                div.pb(len/i);
        }
    }
    return div;
}
int main()
{
    fastIO
    int t;
    cin >> t;
    cin.ignore();
    while(t--)
    {
        string S;
        getline(cin,S);
        vector<ll>freq(26,0),temp;
        ll len = S.length();
        for(int i=0;i<len;i++)
            freq[S[i]-'A']++;
        sort(freq.begin(),freq.end(),greater<int>());
        temp=freq;
        vector<ll>div=getDivisor(len);
//        for(ll i:div)
//            cout<<i<<" ";
        ll result=INT_MAX;
        ll i,j;
        for(ll t=0;t<div.size();t++)
        {
            if(div[t]<=26)
                i=0,j=div[t]-1;
            else if(div[t]>26 && div[t]%26==0)
                i=0,j=25;
            else
                continue;
            ll ans=0;
            while(i<=j)
            {
                ll dif=0;
                ll mark = len/div[t];
                if(div[t]>26 && div[t]%26==0)
                    mark = div[t]/26;
                while(temp[i]!=mark)
                {
                    if(temp[i]<mark)
                    {
                        dif = mark -temp[i];
                        temp[i]+=dif;
                        ans+=dif;
                    }
                    else
                    {
                        temp[i]--,temp[j]++;
                        ans++;
                    }
                    if(temp[j]==mark) j--;

                }
                i++;
                //cout<<"ok";
            }
            //for(int k=i;k<26;k++)
              //  ans+=temp[k];
            if(result>ans)
                result=ans;
           // for(ll k:temp) cout<<k<<" ";
            //cout<<ans<<endl;
            temp=freq;
        }

        cout<<result<<"\n";
    }
    return 0;
}


