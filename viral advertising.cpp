#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,total=0,liked=0,share=5;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        liked=(share/2);
        share=liked*3;
        total+=liked;
    }
    cout<<total;
}
