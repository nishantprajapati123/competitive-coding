#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mk make_pair
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define vi vector < int >
#define pii pair < int, int >
#define INF (int)1e9
#define fastIO ios::sync_with_stdio(0); cin.tie(0);
bool isValid(int i, int j, int r, int c)
{
    return (i>=1 && j>=1 && i<=r && j<=c);
}
int main()
{
    fastIO
    freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        cout<<"Case #"<<z<<": ";
        int r,c;
        cin>>r>>c;
        //queue<pii>que;
        vector<pair<int,int> >path;
        int i=2,j=3;
        pii curr = mk(i,j);
        path.pb(curr);
//        que.push(curr);
        bool  found = false;
        while(path.size()!=(r*c))
        {
        //1st
            if(isValid(i-1,j+1,r,c)  && !found)
            {
                for(int x=i-1;x>=1;x--)
                {
                    for(int y=j+1;y<=c;y++)
                    {
                        if(i+j==x+y || i-j==x-y) continue;
                        if(find(all(path),mk(x,y))==path.end())
                        {
                            i=x,j=y;    //update
                            found=true;
                            path.pb(mk(i,j));
                            break;
                        }
                    }
                }
            }
            //2nd
            if(isValid(i+1,j+1,r,c) && !found)
            {
                for(int x=i+1;x<=r;x++)
                {
                    for(int y=j+1;y<=c;y++)
                    {
                        if(i+j==x+y || i-j==x-y) break;
                        if(find(all(path),mk(x,y))==path.end())
                        {
                            i=x,j=y;
                            found=true;
                            path.pb(mk(i,j));
                            break;
                        }
                    }
                }
            }
            //3rd
            if(isValid(i+1,j-1,r,c) && !found)
            {
                for(int x=i+1;x<=r;x++)
                {
                    for(int y=j-1;y>=1;y--)
                    {
                        if(i+j==x+y || i-j==x-y) break;
                        if(find(all(path),mk(x,y))==path.end())
                        {
                            i=x,j=y;
                            found=true;
                            path.pb(mk(i,j));
                            break;
                        }
                    }
                }
            }
            //4th
            if(isValid(i-1,j-1,r,c) &&!found)
            {
                for(int x=i-1;x>=1;x--)
                {
                    for(int y=j-1;y>=1;y--)
                    {
                        if(i+j==x+y || i-j==x-y) break;
                        if(find(all(path),mk(x,y))==path.end())
                        {
                            i=x,j=y;
                            found=true;
                            path.pb(mk(i,j));
                            break;
                        }
                    }
                }
            }
            if(!found)
            {
                cout<<"IMPOSSIBLE\n";
                break;
            }
            else found=false;
        }
        //if(path.size()==(r*c))
        //{
            cout<<"POSSIBLE\n";
            for(auto x:path)
                cout<<x.first<<" "<<x.second<<"\n";
       // }

    }
}
