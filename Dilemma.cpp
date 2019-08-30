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
    cin.ignore();
    while(t--)
    {
        string cards;
        getline(cin,cards);
        int i = 0;
        while(i<cards.length())
        {
            if((cards[i] == '1')&& (i+1)<cards.length())
                cards[i+1] = cards[i+1]=='1' ? '0':'1';
            i++;
        }
        if(cards[cards.length()-1] == '1')
            cout<<"WIN\n";
        else
            cout<<"LOSE\n";
    }
    return 0;
}
