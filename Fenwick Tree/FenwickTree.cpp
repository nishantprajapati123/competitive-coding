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
#define INF (ll)1e30
#define fastIO ios::sync_with_stdio(0); cin.tie(0);

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

const int N = 100005;
int BIT_tree[N];
int getNext(int index)
{
    return index + (index & -index);
}

int getParent(int index)
{
    return index - (index & -index);
}
//query prefix
int query(int index)
{
    index++;    //point to bit tree index
    int sum = 0;
    while(index > 0)
    {
        sum += BIT_tree[index];
        index = getParent(index);
    }
    return sum;
}
//update tree
void updateBIT(int bit_length, int val ,int index)
{
    //update till index is less than bit tree length
    while(index < bit_length)
    {
        BIT_tree[index] += val;
        index = getNext(index);
    }
}

//build tree
void BIT(vector<int>&input)
{
    int arr_size = input.size();
    int bit_length = arr_size+1;
    for(int i=1;i<=arr_size;i++)
    {
        updateBIT(bit_length, input[i-1], i);
    }
}
int main()
{
    fastIO
    vector<int>input = {1,2,3,4,5,6,7};
    BIT(input);
    //query
    cout<<query(0)<<endl;
    cout<<query(2)<<endl;
    cout<<query(5)<<endl;
    cout<<query(6)<<endl;
    return 0;
}