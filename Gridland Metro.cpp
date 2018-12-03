#include<bits/stdc++.h>

using namespace std;
int main()
{
    long int n,m;
    int k,a;
    long int nocell;
    cin>>n>>m>>k;
    vector<vector<int> >city(n,vector<int>(m,0));
    nocell=(long)n*(long)m;
    while(k--)
    {
        long long int r,c1,c2,cont=0;
        cin>>r>>c1>>c2;
        while(c1-1<=c2-1)
        {
            if(city[r-1][c1++ -1]==0)
            {
                cont++;
                city[r-1][c1-2]++;
            }
        }
        nocell-=cont;
    }
    cout<<nocell;
}
