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
int heightBt(BTNode *root)
{
    queue<BTNode*>que;
    int height=0,n;
    if(root==NULL)
        return -1;
    else if(root->left==NULL && root->right==NULL)
        return 0;
    else
    {
        que.push(root);
        while(!que.empty())
        {
            n=que.size();
            height++;
            while(n>0)
            {
                root=que.front();
                que.pop();
                if(root->left)
                    que.push(root->left);
                if(root->right)
                    que.push(root->right);
                n--;
            }

        }
        return (height-1);

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
    root->left->left->left= create(8);
    cout<<heightBt(root);
}
