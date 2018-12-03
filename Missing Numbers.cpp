#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n,m,i;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>m;
    vector<int>brr(m);
    for(int i=0;i<m;i++)
        cin>>brr[i];
    vector<int>::iterator upper;
    sort(brr.begin(),brr.end());
    i=0;
    while(i<m)
    {
        if(count(brr.begin(),brr.end(),brr[i])!=count(arr.begin(),arr.end(),brr[i]))
        {
            cout<<brr[i]<<" ";
        }
        upper=upper_bound(brr.begin(),brr.end(),brr[i]);
        i=upper-brr.begin();


    }
    return 0;
}
