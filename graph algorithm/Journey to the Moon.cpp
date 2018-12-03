#include<bits/stdc++.h>
using namespace std;

int find_(int x,int parent1[])
{
    while(parent1[x]!=x)
    {
        x=parent1[x];
    }
    return x;
}
void union_(int x,int y, int parent1[])
{
    int px=find_(x,parent1);        //find representative of x
    int py=find_(y,parent1);        //find representative of y
    parent1[px]=py;
}
int main()
{
    int n,p;
    cin>>n>>p;
    int parent1[n];
    for(int i=0;i<n;i++)
        parent1[i]=i;
    int u[p],v[p];
    for(int i=1;i<=p;i++)
    {
        cin>>u[i]>>v[i];
        if(find_(u[i],parent1)!=find_(v[i],parent1))
        {
            union_(u[i],v[i],parent1);      //join if they don't form cycle
        }

    }
    int total_pair=0;
    int i=0,j,k;
    //check for every possible if their representative are different then they form pair
    for(j=i+1;j<n;j++)
    {
        if(find_(i,parent1)!=find_(j,parent1))
        {
            total_pair++;
        }
        if(i==n-2)
            break;
        if(j==n-1)
        {
            i++;
            j=i;
            continue;
        }

    }
    cout<<total_pair<<endl;

}
