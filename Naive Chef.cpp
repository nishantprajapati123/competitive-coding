#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,n,a,b,na=0,nb=0;
        double prob;
        cin>>n>>a>>b;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            if(x==a)
                na++;
            if(x==b)
                nb++;
        }
        //int temp;
        //temp=(na/n)*(nb/n);
        prob=(double(na)/double(n))*(double(nb)/double(n));
        //if(abs(prob-temp) <=0.000001)
            cout<<setprecision(10)<<fixed<<prob<<endl;
    }
}
