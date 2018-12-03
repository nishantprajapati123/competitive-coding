#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    int q,x,y,z;
    int dac,dbc;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>x>>y>>z;
        dac=abs(x-z);
        dbc=abs(y-z);
        if(dac<dbc)
            cout<<"Cat A"<<endl;
        else if(dbc<dac)
            cout<<"Cat B"<<endl;
        else
            cout<<"Mouse C"<<endl;
    }
    return 0;
}
