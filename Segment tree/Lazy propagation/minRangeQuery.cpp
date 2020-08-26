#include<bits/stdc++.h>
using namespace std;

int tree[400005];
int lazyTree[400005];
int A[100005];

void buildTree(int treeId, int low, int high)
{
    if(low == high)
    {
        tree[treeId] = A[low];
        return;
    }
    int mid = (low + high)/2;

    buildTree(2*treeId, low, mid);
    buildTree(2*treeId + 1, mid+1, high);

    tree[treeId] = min(tree[2*treeId], tree[2*treeId + 1]);
}

void update(int treeId, int uLow, int uHigh, int low, int high, int val)
{
    if(low > high)  return;

    //check for pending update
    if(lazyTree[treeId] != 0)
    {
        tree[treeId] += lazyTree[treeId];
        //not leaf then propagate
        if(low != high)
        {
            lazyTree[2*treeId] += lazyTree[treeId];
            lazyTree[2*treeId + 1] += lazyTree[treeId];
        }
        lazyTree[treeId] = 0;
    }

    //no overlap
    if(low > uHigh || high < uLow)  return;

    //total overlap
    if(uLow <= low && uHigh >= high)
    {
        tree[treeId] += val;
        //propagate update
        if(low != high)
        {
            lazyTree[2*treeId] += val;
            lazyTree[2*treeId + 1] += val;
        }
        return;     //dont go down
    }

    //partial
    int mid = (low + high)/2;
    update(2*treeId, uLow, uHigh, low, mid, val);
    update(2*treeId + 1, uLow, uHigh, mid + 1, high, val);

    tree[treeId] = min(tree[2*treeId], tree[2*treeId + 1]);
}

int query(int treeId, int qLow, int qHigh, int low, int high)
{
    if(low > high)  return INT_MAX;

    //check for pending update
    if(lazyTree[treeId] != 0)
    {
        tree[treeId] += lazyTree[treeId];
        if(low != high)
        {
            lazyTree[2*treeId] += lazyTree[treeId];
            lazyTree[2*treeId + 1] += lazyTree[treeId];
        }
        lazyTree[treeId] = 0;
    }

    //no overlap
    if(qLow > high || qHigh < low)  return INT_MAX;

    //total overlap
    if(qLow <= low && qHigh >= high)
    {
        return tree[treeId];
    }

    //partial overlap
    int mid = (low + high)/2;

    return min(query(2*treeId, qLow, qHigh, low, mid),
               query(2*treeId + 1, qLow, qHigh, mid + 1, high));
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)    cin>>A[i];

    buildTree(1, 0, n-1);
    int q, t, x, y, val;
    cin>>q;
    while(q--)
    {
        cin>>t;
        if(t == 1)
        {
            cin>>x>>y>>val;
            update(1, x, y, 0, n-1, val);   //increment 
        }
        else
        {
            cin>>x>>y;
            cout<<x<<" "<<y<<" = "<<query(1, x, y, 0, n-1)<<"\n";
        }
    }
    return 0;
}