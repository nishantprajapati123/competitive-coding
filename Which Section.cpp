#include<bits/stdc++.h>
using namespace std;
int whichSection(int n, int k, int m, vector<int>a)
{
    int total=0;
    int section=0;
    for(int i=0;i<n;i++)
    {
        total+=a[i];
        section++;
        if(k<=total)
            break;
    }
    return section;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int result;
        int n,k,m;
        cin>>n>>k>>m;
        vector<int>a(m);
        for(int i=0;i<m;i++)
            cin>>a[i];
        result=whichSection(n,k,m,a);
        cout<<result<<endl;
    }
}
