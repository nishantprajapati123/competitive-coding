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
int main()
{
    fastIO
    int nooftestcase;
    cin>>nooftestcase;
    for(int testcase = 1;testcase<=nooftestcase;testcase++)
    {
        int n;
        cin>>n;
        vector<vector<int> >mat(n, vector<int>(n));

        int sum = 0;
        int rowCount = 0, colCount = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>mat[i][j];
                if(i == j)  sum += mat[i][j];
            }
        }

        //row check
        for(int i=0;i<n;i++)
        {
            int sum1 = 0, sum2 = 0;
            for(int j=0;j<n;j++)
            {
                sum1 += mat[i][j];
                sum2 += mat[i][j] * mat[i][j];
            }
            if(sum1 != (n*(n+1))/2  || sum2 != (n*(n+1)*(2*n+1))/6)
                rowCount++;
        }

        //col check
        for(int j=0;j<n;j++)
        {
            int sum1 = 0, sum2 = 0;
            for(int i=0;i<n;i++)
            {
                sum1 += mat[i][j];
                sum2 += mat[i][j] * mat[i][j];
            }
            if(sum1 != (n*(n+1))/2  || sum2 != (n*(n+1)*(2*n+1))/6)
                colCount++;
        }

        cout<<"Case #"<<testcase<<": "<<sum<<" "<<rowCount<<" "<<colCount<<"\n";
    }
    return 0;
}
