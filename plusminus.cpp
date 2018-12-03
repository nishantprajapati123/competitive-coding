#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
vector<int>c(3,0);
void minuspluse(int a[],int n)
{
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            if(a[i]>0)
                c[0]+=1;
            else if(a[i]<0)
                c[1]+=1;
            else
                c[2]+=1;
        }
        for(int i=0;i<c.size();i++)
        {
           cout<<fixed<<setprecision(6)<<((double)c[i]/(double)n)<<endl;
        }
}
int main()
{
    //vector<int>a;
    int a[100];
    int n;
    cin>>n;
    minuspluse(a,n);
    return 0;
}
