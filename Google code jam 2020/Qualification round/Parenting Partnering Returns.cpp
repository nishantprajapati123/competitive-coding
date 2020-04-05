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

bool comp(const vector<int>&A, const vector<int>&B)
{
    if(A[0] == B[0])
        return A[2] < B[2];
    return A[0] < B[0];
}
int main()
{
    fastIO
    int nooftestcase;
    cin>>nooftestcase;
    for(int testcase = 1;testcase<=nooftestcase;testcase++)
    {
        int n;
        cin>>n;

        vector<vector<int> >task(n, vector<int>(3));
        for(int i=0;i<n;i++)
        {
            cin>>task[i][0]>>task[i][1];
            task[i][2] = i;
        }

        //sort according to start time (in-place);
        sort(task.begin(),task.end(),comp);

        int Cend = -1, Jend = -1;
        bool found = true;
        vector<char>ans(n);

        for(int i=0;i<n;i++)
        {
            if(Cend == -1 || task[i][0] >= Cend)
            {
                Cend = task[i][1];
                ans[task[i][2]] = 'C';
            }
            else if(Jend == -1 || task[i][0] >= Jend)
            {
                Jend = task[i][1];
                ans[task[i][2]] = 'J';
            }
            else
            {
                found = false;
                break;
            }
        }

        cout<<"Case #"<<testcase<<": ";
        if(found)
        {
            for(char ch:ans)
                cout<<ch;
        }
        else
            cout<<"IMPOSSIBLE";
        cout<<"\n";

    }
    return 0;
}
