#include<bits/stdc++.h>
using namespace std;
void newYearChoas(vector<int>arr, int n)
{
    int i=n,cnt,j,total=0,key,k;
    bool c=false;
    for(cnt=0;cnt<n;cnt++)
    {
        int max_=0;
        for(j=0;j<n-cnt;j++)    //find max after each cnt iteration
        {
            if(arr[j]>max_)
            {
                max_=arr[j];
                k=j;
            }
        }
        key=arr[k];
        int inc=0;
        while(k<i-1)
        {
            arr[k]=arr[k+1];
            inc++;
            k++;
        }
        i--;arr[k]=key;
        if(inc>2)
        {
            c=true;
            break;
        }
        else
            total+=inc;
    }
    if(c)
        cout<<"Too chaotic"<<endl;
    else
        cout<<total<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        newYearChoas(arr,n);
    }
}
