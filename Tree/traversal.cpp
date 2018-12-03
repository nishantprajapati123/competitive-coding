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
void recurPreorder(BTNode *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        recurPreorder(root->left);
        recurPreorder(root->right);
    }
}
void NonrecrPreorder(BTNode *root)
{
    stack<BTNode*>st;
    while(true)     //if stack is empty then break;
    {
        while(root)
        {
            cout<<root->data<<" ";
            st.push(root);
            root=root->left;    //go left till null
        }
        if(st.empty())
            break;
        root=st.top();
        st.pop();
        root=root->right;

    }
}
void NonrecrInorder(BTNode *root)
{
    stack<BTNode*>st;
    while(true)
    {
        while(root)
        {
            st.push(root);
            root=root->left;
        }
        if(st.empty())
            break;
        root=st.top();  //process current node
        st.pop();
        cout<<root->data<<" ";
        root=root->right;   //go to right subtree
    }
}
void levelOrder(BTNode *root)
{
    queue<BTNode*>que;
    if(!root)
        return;
    que.push(root); //insert root address
    while(!que.empty())
    {
        BTNode* temp;
        temp=que.front();
        que.pop();
        cout<<temp->data<<" ";
        if(temp->left)
            que.push(temp->left);
        if(temp->right)
            que.push(temp->right);
    }
}
int main()
{
    BTNode *root= create(1);
    root->left= create(2);
    root->right= create(3);
    root->left->left = create(4);
    root->left->right= create(5);
    root->right->left= create(6);
    root->right->right= create(7);
    recurPreorder(root);
    cout<<endl;
    NonrecrPreorder(root);
    cout<<"\nInorder\n";
    NonrecrInorder(root);
    cout<<"\nLevel order\n";
    levelOrder(root);
}

