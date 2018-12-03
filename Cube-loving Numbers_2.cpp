#include<bits/stdc++.h>
typedef long int ll;
using namespace std;

ll cubeLoving(ll n)
{
    int n_t=pow(n,(1.0/3.0));
    int n_temp=n_t+1;
    cout<<n_t<<" "<<n_temp;
    vector<ll>cube(n_temp);
    for(int i=0;i<n_temp;i++)
        cube[i]=i*i*i;
    //vector for storing
    cout<<endl;
    vector<ll>store(n_temp);
    int cont=0,temp_cont;
    for(int i=2;i<n_temp;i++)
    {
        temp_cont=n/cube[i];
        store[i]=temp_cont;
        cont+=temp_cont;
    }
    return 0;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        cout<<cubeLoving(n)<<endl;
    }
}
