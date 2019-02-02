#include <bits/stdc++.h>
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
//bool isValid(int x, int y)
//{
//    return (x>=0 && x<n && y>=0 && y<m);
//}
int main()
{
    fastIO
    int t;
    cin >> t;

    while(t--)
    {
        int n,m;
        cin>>n>>m;
//        vector<vector<int> >grid(n,vector<int>(m,0));
        vector<vector<int> >grid(n);
        for(int i=0;i<n;i++)
        {
            grid[i].resize(m);
            for(int j=0;j<m;j++)
                grid[i][j]=0;
        }
        int vect1[]={1,1,2,2};
        int vect2[3][3]={{1,2,3},{1,2,3}};
        int vect3[2][2]={{1,2},{3,4}};
        int vect4[2][2]={{2,1},{4,3}};
        if(n==1 && m==1)
            cout<<"1\n1\n";
        else if((n==1&& m>1))
        {
            for(int i=0;i<m;i++)
                grid[0][i]=vect1[i%4];
            if(m<=2)
                cout<<"1\n";
            else
                cout<<"2\n";
            for(int i=0;i<m;i++)
                cout<<grid[0][i]<<" ";
            cout<<"\n";
        }
        else if(n>1 && m==1)
        {
            for(int i=0;i<n;i++)
                grid[i][0]=vect1[i%4];
            if(n<=2)
                cout<<"1\n";
            else
                cout<<"2\n";
            for(int i=0;i<n;i++)
                cout<<grid[i][0]<<"\n";
        }
        else if(n==2 && m>1)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                    grid[i][j]=vect2[i%2][j%3];
            }
            if(m==2)
                cout<<"2\n";
            else
                cout<<"3\n";
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                    cout<<grid[i][j]<<" ";
                cout<<"\n";
            }
        }
        else if(n>2 && m==2)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                    grid[i][j]=vect2[j%2][i%3];
            }
            if(n==2)
                cout<<"2\n";
            else
                cout<<"3\n";
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                    cout<<grid[i][j]<<" ";
                cout<<"\n";
            }
        }
        else if(n>=3 && m>=3)
        {
            bool flip = true;
            for(int i=0;i<n;i++)
            {
                if(i%2==0) flip =!flip;
                int k=0;
                for(int j=(i%2==0?0:1);j<m;j+=2)
                {
                    if(!flip)
                        grid[i][j] = vect3[i%2][(k++)%2];
                    else
                        grid[i][j] = vect4[i%2][(k++)%2];
                }
            }
            for(int i=1;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(grid[i][j]==0) grid[i][j]=grid[i-1][j];
                }
            }
            int k=0;
            for(int i=1;i<n;i+=2)
                grid[0][i]=(k++)%2==0?4:3;
            cout<<"4\n";
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<m;j++)
                    cout<<grid[i][j]<<" ";
                cout<<"\n";
            }

        }
    }
}
