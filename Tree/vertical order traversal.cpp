#include<bits/stdc++.h>
#define add(a,b) insert(make_pair(a,b))
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
void verOrderTraverse(BTNode *root)
{
    queue<pair<BTNode*,int> >que;
    map<int,vector<int> >mapping;
    int hd=0;
    pair<BTNode*,int> temp;
    que.push(make_pair(root,hd));
    mapping[hd].push_back(root->data);
    while(!que.empty())
    {
        BTNode* node;
        temp=que.front();
        que.pop();
        node=temp.first;
        int hdd=temp.second;
        if(node->left)
        {
            mapping[hdd-1].push_back(node->left->data);         //push into hash table
            que.push(make_pair(node->left,hdd-1));              //push into queue
        }
        if(node->right)
        {
            mapping[hdd+1].push_back(node->right->data);        //push into hash table
            que.push(make_pair(node->right,hdd+1));             //push into queue
        }
    }
    map<int,vector<int> >::iterator it;
    for(it=mapping.begin();it!=mapping.end();++it)
    {
        for(int i=0;i<(*it).second.size();i++)
            cout<<it->second[i]<<" ";
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
    verOrderTraverse(root);
}
