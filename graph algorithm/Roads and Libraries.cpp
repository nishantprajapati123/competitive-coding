#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int find_(int x,vector<int>parent)            //this function finds the representative of subset
{
    while(parent[x]!=x)
    {
        x=parent[x];
    }
    return x;
}
int union_(int x,int y,vector<int>parent)
{
    int px=find_(x,parent);        //find representative of x
    int py=find_(y,parent);        //find representative of y
    parent[px]=py;
}
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int n,m,clib,croad,cycle=0,city_sep=0;
        cin>>n>>m>>clib>>croad;
        vector<int>u(m),v(m);
        for(int i=0;i<m ;i++)
        {
            cin>>u[i]>>v[i];
        }
        vector<int>parent(n+1,-1);
        for(int i=1;i<n+1;i++)
            parent[i]=i;
        for(int i=0;i<m;i++)
        {
            if(find_(u[i],parent)!=find_(v[i],parent))
                union_(u[i],v[i],parent);

            else
                cycle++;
        }
        int min_road_build=m-cycle;
        for(int i=1;i<n+1;i++)
        {
            if(parent[i]==i)
                city_sep++;
        }
        int min_lib=city_sep;
        int prev_cost=INF,pres_cost;

        while(min_lib<=n && min_road_build>=0)
        {
            pres_cost=((min_lib++)*clib)+((min_road_build--)*croad);
            if(prev_cost>pres_cost)
                prev_cost=pres_cost;
            else
            {
                pres_cost=prev_cost;
                break;
            }


        }
        cout<<pres_cost<<endl;
    }
}
