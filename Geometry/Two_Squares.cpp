#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mk make_pair
#define deb(x) cout << #x << "=" << x << endl
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define MOD 1000000007
#define INF (int)1e9
#define fastIO ios::sync_with_stdio(0); cin.tie(0);
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;


//check if any point within -100 to 100 lies on both the square? or not?
int area(int x1, int y1, int x2, int y2, int x3, int y3 )
{
    int A = (x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))/2;

    return A<0?-A:A;
}
struct point
{
    int X[4];
    int Y[4];

    void read()
    {
        for(int i=0;i<4;i++)
            scanf("%d%d", &X[i], &Y[i]);
    }

    bool inside(int x, int y)
    {
        int s1 = 0, s2 = 0;
        for(int i=0;i<4;i++)
        {
            s1 += area(X[0],Y[0], X[i], Y[i], X[(i+1)%4], Y[(i+1)%4]);
            s2 += area(x, y, X[i], Y[i], X[(i+1)%4], Y[(i+1)%4]);
        }

        return s1 == s2;
    }


};
string solve()
{
    point S1;
    point S2;
    S1.read();
    S2.read();
    
    bool found = false;
    for(int i=-100;i<=100;i++)
    {
        for(int j=-100;j<=100;j++)
            if(S1.inside(i,j) && S2.inside(i,j))
            {
                found = true;
                printf("YES\n");
                break;
            }

            if(found)   break;
    }
    if(!found)
        printf("NO");
    
}
int main()
{
    fastIO
    solve();
    return 0;
}