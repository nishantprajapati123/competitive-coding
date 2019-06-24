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
void levelOrder(node *root)
{
    queue<node*>que;
    if(root == NULL)
        cout<<"Tree is empty\n";
    else
    {
        // node *tmp = root;
        que.push(root);
        while(!que.empty())
        {
            node *tmp = que.front();
            que.pop();
            cout<<tmp->data<<" ";
            if(tmp->left)
                que.push(tmp->left);
            if(tmp->right)
                que.push(tmp->right);
        }
    }
}
int main()
{
//    node *root = NULL;
    node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(6);
    root->left->right = createNode(7);
    root->right->left = createNode(4);
    root->right->right = createNode(5);
    levelOrder(root);
}
