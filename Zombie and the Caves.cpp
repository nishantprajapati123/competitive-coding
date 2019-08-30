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
//    freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<ll>C(N),H(N);
        for(int i=0;i<N;i++)    cin>>C[i];
        for(int i=0;i<N;i++)    cin>>H[i];

        vector<ll>temp(N,0);
        vector<ll>radLevel(N,0);
        ll l,r;
        for(int i=0;i<N;i++)
        {
            l = ((i+1)-C[i])>0 ? (i+1)-C[i]-1 : 0;
            r = ((i+1)+C[i])>N ? N-1 : (i+1)+C[i]-1;
            //update range
            temp[l]++;
            if(r!=N-1)
                temp[r+1]--;
        }
        //retrieve original array using prefix sum
        radLevel[0] = temp[0];
        for(int i=1;i<N;i++)
            radLevel[i] = radLevel[i-1] + temp[i];


        unordered_map<ll,ll>freq_rad;
        for(int i = 0;i<N;i++)
            freq_rad[radLevel[i]]++;
        bool kill = true;
        for(int i= 0 ;i<N;i++)
        {
            if(freq_rad.find(H[i])!=freq_rad.end())
            {
                if(freq_rad[H[i]])
                    freq_rad[H[i]]--;
                else
                {
                    kill = false;
                    break;
                }
            }
            else{
                kill = false;
                break;
            }
        }
        if(kill)    cout<<"YES\n";
        else    cout<<"NO\n";

    }
    return 0;
}

