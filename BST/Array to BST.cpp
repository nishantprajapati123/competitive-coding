#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left,*right;
};
node* create(int key)
{
    node *temp=new node;
    temp->data=key;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void preOrder(node *root)
{

    if( root == NULL )
        return;
    cout << root->data << " ";

    preOrder(root->left);
    preOrder(root->right);
}
node* arrayToBST(vector<int>arr, int low, int high)
{
    //base condition
    if(low>high)
        return NULL;
    //get the middle and make it root node;
    int mid=(low+high)/2;
    node *Node= create(arr[mid]);
    // do same for left sub array and make it root as left child of root
    //which is previously created
    Node->left=arrayToBST(arr,low,mid-1);
    // do same for right sub array and make it root as right child of root
    //which is previously created
    Node->right=arrayToBST(arr,mid+1,high);

    //return root node
    return Node;

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        node* root=NULL;
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        root=arrayToBST(arr,0,n-1);
        preOrder(root);
        cout<<endl;
    }
}
