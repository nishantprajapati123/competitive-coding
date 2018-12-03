#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k,rem,num,rev=0;
    int bd=0;
    cin>>i>>j>>k;
    while(i<=j)
    {
        num=i;
        rev=0;
        while(num>0)
        {
        rem=num%10;
        rev=rev*10+rem;
        num=num/10;
        }
        if(abs(i-rev)%k==0)
            bd++;
        i++;

    }
    cout<<bd;
}

