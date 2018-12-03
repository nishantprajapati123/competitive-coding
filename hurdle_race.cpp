#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,k,min_magic=0,max_h;
    cin>>n>>k;
    vector<int>height(n);
    for(int i=0;i<n;i++)
    {
        cin>>height[i];
    }
    max_h=height[0];
    for(int i=0;i<n;i++)
    {
        if(height[i]>=max_h)
            max_h=height[i];

    }
    if(max_h-k>0)
        cout<<max_h-k;
    else
        cout<<min_magic;
    return 0;
}
