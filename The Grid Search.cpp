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
//int grid[1000][1000];
//int pattern[1000][1000];
bool isValid(int x, int y, int R, int C)
{
    return (x>=0 && y>=0 && x<R && y<C);
}
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        int R,C;
        cin>>R>>C;
        cin.ignore();
        //enter grid
        vector<string> grid(R);
        for(int i = 0; i < R; i++) {
            string G_item;
            getline(cin, G_item);

            grid[i] = G_item;
        }
        int r,c;
        cin>>r>>c;
        cin.ignore();
        //enter pattern
        vector<string> pattern(r);

        for (int i = 0; i < r; i++) {
            string P_item;
            getline(cin, P_item);

            pattern[i] = P_item;
        }
        bool found=false;
        int cont=0;
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                if(grid[i][j]==pattern[0][0] && isValid(i+r-1,j+c-1,R,C) && grid[i+r-1][j]==pattern[r-1][0] && grid[i][j+c-1]==pattern[0][c-1] && grid[i+r-1][j+c-1]==pattern[r-1][c-1])
                {
                    bool notfound=false;
                    int k=i,x=0;
                    cont=0;
                    while(k<(i+r) && x<r)
                    {
                        int l=j,y=0;
                        while(l<(j+c) && y<c)
                        {
                            if(grid[k][l]!=pattern[x][y])
                            {
                                notfound=true;
                                break;
                            }
                            l++,y++;
                            cont++;
                        }
                        if(notfound) break;
                        //cout<<cont<<" ";

                        k++,x++;
                    }
                }
                if(cont==(r*c))
                {
                    cout<<"YES"<<"\n";
                    found=true;
                    break;
                }
            }
            if(found) break;
        }
        if(cont!=(r*c)) cout<<"NO"<<"\n";
    }
}



