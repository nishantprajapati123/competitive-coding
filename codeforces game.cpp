#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<long int>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a.begin(),a.end());
    a.erase(a.end()-1);
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<" ";
}
