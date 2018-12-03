#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int n,d;
    int notification=0,median,sr=0,ind;
    cin>>n>>d;
    vector<long int>exp(n);

    for(int i=0;i<n;i++)
        cin>>exp[i];
    for(int i=d+1;i<=n;i++)
    {
        vector<long int>expenditure(exp.begin(),exp.end());
        sort(expenditure.begin()+sr,expenditure.begin()+sr+d);
        if(n%2!=0)
        {
            ind=d/2;
            median=expenditure[ind+sr];
        }else{
            ind=d/2;
            median=(expenditure[ind-1+sr]+expenditure[ind+sr])/2;
        }
        if(expenditure[i-1]>=2*median)
            notification++;
        sr++;

    }
    cout<<notification;


}
