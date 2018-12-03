#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    long k;
    cin>>n>>k;
    vector<long long>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    int cnt=0;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++)
    {
        if(binary_search(a.begin(),a.end(),(a[i]+k)))
            cnt++;
        if(a[i]+k>a[n-1])
            break;
    }
    cout<<cnt<<endl;
}
