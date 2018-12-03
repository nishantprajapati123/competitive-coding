#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
   // vector<vector<int> >contest(n);
   int luck=0;
   vector<int>temp;
    for(int i=0;i<n;i++)
    {
        int lck;
        int imp;
        cin>>lck;
        luck+=lck;
        cin>>imp;
        if(imp==1)
            temp.push_back(lck);
    }
    //sort
    sort(temp.begin(),temp.end());
     int mustwin=temp.size()-k;
     if(mustwin==0)
        cout<<luck;
     else
     {
         for(int i=0;i<mustwin;i++)
            luck-=(2*temp[i]);
         cout<<luck;
     }


}
