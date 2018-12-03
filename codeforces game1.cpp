#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,no;
    cin>>n;
    list<long int>a;
    list<long int>::iterator it;
    for(int i=0;i<n;i++)
    {
        cin>>no;
        a.push_back(no);
    }
    a.sort();
    for(int i=1;i<=n-1;i++)
    {
        if(i%2!=0)
            a.pop_back();
        else
            a.pop_front();
    }
    for(it=a.begin();it!=a.end();it++)
        cout<<*it<<" ";
}
