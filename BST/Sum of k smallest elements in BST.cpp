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
node* insertNode(node *root, int key)
{
    if(root==NULL)
        return create(key);
    else if(key < root->data)
        root->left= insertNode(root->left,key);
    else if(key > root->data)
        root->right= insertNode(root->right,key);
    return root;
}
void preOrder(node *root, priority_queue<int,vector<int>,greater<int> >&minHeap) {

    if( root == NULL )
        return;
    minHeap.push(root->data);

    //cout << root->data << " ";

    preOrder(root->left,minHeap);
    preOrder(root->right,minHeap);
      }
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        priority_queue<int,vector<int>,greater<int> >minHeap;
        node *root=NULL;
        int n;
        cin>>n;
        int k;
        for(int i=1;i<=n;i++)
        {
            int a;cin>>a;
            root=insertNode(root,a);
        }
        cin>>k;
        preOrder(root,minHeap);
        int sum=0;
        while(k!=0)
        {
            int u=minHeap.top();minHeap.pop();
            sum+=u;
           //cout<<u<<" ";
            k--;
        }
        cout<<sum<<endl;
    }
}
