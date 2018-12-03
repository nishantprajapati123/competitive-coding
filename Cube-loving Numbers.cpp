#include<bits/stdc++.h>
using namespace std;
long int cubeLoving(long int n)
{
    set<long>uniq;
    float n_t=pow(n,1.0/3.0);
    //make array of length n_temp
    int n_temp=n_t+1;
    cout<<n_t<<" "<<n_temp;
    vector<long>cube(n_temp);
    for(int i=0;i<n_temp;i++)
        cube[i]=i*i*i;
    int cont=0,temp_cont=0,repeat=0;
    vector<long>storecont(n_temp);
   // cout<<n_temp<<endl;
    //for(int i=0;i<n_temp+1;i++)
      //  cout<<cube[i]<<" ";
    //cout<<endl;
    for(int i=2;i<n_temp;i++)
    {
        temp_cont=n/cube[i];
        storecont[i]=temp_cont;
        cont+=temp_cont;
    }
    int i=2;
    while(i<n_temp)
    {
        int j=1;
        while(j<=storecont[i])
        {
            uniq.insert(cube[i]*j);
            j++;
        }
        i++;
    }
    return uniq.size();
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long int n;
        cin>>n;
        cout<<cubeLoving(n)<<endl;
    }


}
