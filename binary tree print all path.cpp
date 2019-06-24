#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left,*right;
    node()
    {
        this->left = NULL;
        this->right = NULL;
    }
};

node* createNode(int data)
{
    node* new_node = new node;
    new_node->data = data;
    return new_node;
}
vector<int>path;
void dfs(node *root)
{
    if(root == NULL)
        return;
    path.push_back(root->data);
    if(root->left == NULL && root->right == NULL)
    {
        for(int x:path)
            cout<<x<<" ";
        cout<<"\n";
    }
    dfs(root->left);
    dfs(root->right);
     path.pop_back();
}
int main()
{
//    node *root = NULL;
    node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
//    root->left->left = createNode(4);
//    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
//    levelOrder(root);
    dfs(root);
}
