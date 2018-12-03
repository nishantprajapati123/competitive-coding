#include<bits/stdc++.h>
using namespace std;
int totalForecastInaccuracy(vector<int>t ,vector<int>f)
{
    int result=0,i,j;
    for(i=0;i<7;i++)
        result+=abs(t[i]-f[i]);
    return result;
}
int main()
{
    int i,j;
    vector<int>t(7);
    vector<int>f(7);
    for(i=0;i<7;i++)
        cin>>t[i];
    for(j=0;j<7;j++)
        cin>>f[j];
    cout<<totalForecastInaccuracy(t,f);
}
