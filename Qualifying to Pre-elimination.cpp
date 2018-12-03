#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,i=0;
        cin>>n>>k;
        vector<int>s(n);
        for(int i=0;i<n;i++)
            cin>>s[i];
        int res=0;
        sort(s.begin(),s.end(),greater<int>());
        int key=s[k-1];
        while(s[i]>=key && i<n){
            res++,i++;
        }
        cout<<res<<"\n";
    }
}
