#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,k,result=0;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if((a[i]+a[j])%k==0)
                result+=1;
        }
    }
    cout<<result;
    return 0;

}
