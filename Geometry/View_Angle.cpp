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

// bool comp()
struct mannequin
{
    double x;
    double y;
};
void solve()
{
    int n;
    scanf("%d",&n);

    mannequin mann[n];
    for(int i=0;i<n;i++)
    {
        scanf("%lf%lf", &mann[i].x, &mann[i].y);
    }

    vector<double>angle;
    for(auto m:mann)
    {
        double a = atan2(m.y,m.x);
        a = a*180/acos(-1);
        if(a < 0 )
            a+=360.0;
        // printf("%lf ",a);
        angle.pb(a);
    }



    sort(angle.begin(),angle.end());
    double minAngle = angle[n-1] - angle[0];    //consider 1st and last
    for(int i=0;i<n-1;i++)
        minAngle = min(minAngle, 360.0 - (angle[i+1] - angle[i]));

    printf("%.10lf\n",minAngle);


}
int main()
{
    fastIO
    solve();
    return 0;
}