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
int A[101][101];
bool isValid(int x, int y, int h, int w)
{
    return(x>=0 && y>=0 && x<h && y<w);
}
int main()
{
    fastIO
    int H,W;
    cin>>H>>W;
    ll area=0;
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
            cin>>A[i][j];
    }
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            //add top and bottom surface area
            area+=(2*1*1);
            //check for left
            if(isValid(i,j-1,H,W))
            {
                if(A[i][j] > A[i][j-1])
                    area+=(A[i][j]-A[i][j-1])*1;
            }
            else
                area+=(A[i][j]*1);
            //check for right
            if(isValid(i,j+1,H,W))
            {
                if(A[i][j] > A[i][j+1])
                    area+=(A[i][j]-A[i][j+1])*1;
            }
            else
                area+=(A[i][j]*1);
            //check for front
            if(isValid(i-1,j,H,W))
            {
                if(A[i][j] > A[i-1][j])
                    area+=(A[i][j]-A[i-1][j])*1;
            }
            else
                area+=(A[i][j]*1);
            //check for back
            if(isValid(i+1,j,H,W))
            {
                if(A[i][j] > A[i+1][j])
                    area+=(A[i][j]-A[i+1][j])*1;
            }
            else
                area+=(A[i][j]*1);
        }
    }
    cout<<area<<"\n";
    return 0;
}



