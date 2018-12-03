#include<bits/stdc++.h>
using namespace std;
double computeTimeToLearn(int no)
{
    int m,s;
    double result=0.0;
    for(int i=1;i<=no;i++)
    {
        cout<<"\nEnter time for "<<i<<" lecture (min sec)";
        cin>>m>>s;
        result=result+m;
        result=result+(s/60);
    }
    return result;
}
int main()
{
    int no;
    double r;
    cout<<"\nEnter number of lectures: ";
    cin>>no;
    r=computeTimeToLearn(no);
    if(r<=60.00)
        cout<<r<<" minute";
    else
        cout<<(r/60.00)<<" hour";
    return 0;
}
