#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int count_[n+1];
    //either place vertically or horizontally
    //base condition
    for(int i=1;i<=n;i++)
    {
        //base condition
        if(i==1)
            count_[i]=1;
        else if(i==2)
            count_[i]=2;
        else
            count_[i]=count_[i-1]+count_[i-2];
    }
    cout<<count_[n];
}
