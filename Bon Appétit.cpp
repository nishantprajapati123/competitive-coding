#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,bcharge,bactual;
    int total=0;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>bcharge;
    for(int i=0;i<n;i++)
    {
        if(i!=k)
            total+=a[i];
    }
    bactual=total/2;
    if(bcharge-bactual==0)
        cout<<"Bon Appetit";
    else
        cout<<bcharge-bactual;
}
