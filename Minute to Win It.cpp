/*#include<bits/stdc++.h>
//#define min_prev 0x3f3f3f3f
using namespace std;
int main()
{
    int min_prev=100000;
    int n,k,minute=0;
    cin>>n>>k;
    vector<int>a(n),a1(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    a1=a;
    int j,m,l;
    for(int i=0;i<n;i++)
    {
        a=a1;
        minute=0;
        j=l=i;
        while(j>0)
        {
            m=a[j]-k;
            if((a[j]-k)!=a[--j])
            {
                a[j]=m;
                minute++;
            }
        }
        while(l<n-1)
        {
            m=a[l]+k;
            if((a[l]+k)!=a[++l])
            {
                a[l]=m;
                minute++;
            }
        }

        if(min_prev>minute)
            min_prev=minute;

    }
    cout<<min_prev<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int a[n],cntr=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int i=1;
    while(i<n-1)
    {
        if((a[i]-a[i-1])!=k && (a[i+1]-a[i])!=k && (a[i+1]-a[i-1])==2*k)
        {
            a[i]=a[i-1]+k;
            cntr++;
        }
        i++;
    }
    int z=0;
    for(int i=1;i<n;i++)
    {
        if((a[i]-a[i-1])!=k)
            z++;
    }
    cout<<cntr+z<<endl;

}


