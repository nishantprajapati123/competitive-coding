#include<bits/stdc++.h>
using namespace std;
struct BTNode
{
    int data;
    BTNode *left,*right;
};
BTNode* create(int key)
{
    BTNode *temp = new BTNode;
    temp->data=key;
    temp->left=temp->right=NULL;
    return temp;
}
int maximum(BTNode* root)
{
    int max_,lmax,rmax,curr;
    if(root==NULL)
        return INT_MIN;
    curr=root->data;
    lmax=maximum(root->left);
    rmax=maximum(root->right);
    max_=lmax>rmax?lmax:rmax;
    if(max_>curr)
        return max_;
    else
        return curr;

}
int main()
{
    BTNode *root= create(1);
    root->left= create(2);
    root->right= create(3);
    root->left->left = create(4);
    root->left->right= create(10);
    root->right->left= create(6);
    root->right->right= create(7);
    root->left->left->left= create(8);
    cout<<maximum(root);
}
