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
void solve()
{
    int n;
    scanf("%d",&n);
    int p=1;

    if(n == 1)
        printf("1\n1 1\n");
    else
    {
        int minDay = n/2;
        printf("%d\n", minDay);
        if(n%2 == 0)
        {
            for(int i=1;i<=minDay;i++)
                printf("2 %d %d\n",p++, p++);
        }
        else
        {
            p += 3;
            printf("3 1 2 3\n");
            for(int i=1;i<minDay;i++)
                printf("2 %d %d\n", p++, p++);
        }
    }
}
int main()
{
    fastIO
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase<=T; testcase++)
    {
        solve();
    }
    return 0;
}

