#include<bits/stdc++.h>
using namespace std;
int invalid=0;
void modifier(vector<int>&a,int n,int current,int next)
{
    if(next==n) //base condition
        return;
    if((a[next]!=invalid )&& (a[next]==a[current]))
    {
        a[current]*=2;
        a[next]=invalid;
    }
    modifier(a,n,current+1,next+1);

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n),temp;
        for(int i=0;i<n;i++)
            cin>>a[i];
        modifier(a,n,0,1);
        for(int i=0;i<n;i++)
        {
            if(a[i]!=invalid)
            {
                temp.push_back(a[i]);
            }
        }
        while(temp.size()!=n)
        {
            temp.push_back(invalid);
        }
        for(int i=0;i<temp.size();i++)
            cout<<temp[i]<<" ";
        cout<<endl;
    }
}

