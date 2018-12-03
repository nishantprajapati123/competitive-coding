#include<bits/stdc++.h>
using namespace std;
int greadyFloriest(vector<int>c, int n, int k)
{
    int freq[k+1];
    memset(freq,0,sizeof(freq));
    int i=0;
    int temp=k;
    sort(c.begin(),c.end(),greater<int>());
    int res=0;
    while(i<n && temp)
    {
        res+=(freq[temp]+1)*c[i];
        freq[temp]+=1;
        temp--;
        i++;
        if(!temp)
            temp=k;
    }
    return res;
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>c(n);
    for(int i=0;i<n;i++)
        cin>>c[i];
    cout<<greadyFloriest(c,n,k);
}
