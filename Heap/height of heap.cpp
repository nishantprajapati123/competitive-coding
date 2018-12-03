#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int i=0;
        int height=0;
        while(((2*i)+1)<n)
        {
            i=(2*i)+1;
            height++;
        }
        cout<<height<<endl;
    }
}
