#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *next,*prev;
    node()
    {
        this->next = NULL;
        this->prev = NULL;
    }
};

node* insertNode(node *root, int data)
{
    node* new_node = new node;
    new_node->data = data;
    if(root == NULL)
    {
        root = new_node;
    }
    else
    {
        node *temp = root;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
    return root;

}
bool isPalindrome(node *root)
{
    node *i=root,*j=root;
    while(j->next != NULL)
    {
        j = j->next;
    }
    while(i!=j && i->next!=j)
    {
        if(i->data!=j->data)
            return false;
        i = i->next;
        j = j->prev;
    }
    if((i->next == j) && (i->data!=j->data))
        return false;
    return true;
}
void display(node *root)
{
    node *temp = root;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp =temp->next;
    }
}
int main()
{
    int n;
    cin>>n;
    node *root = NULL;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        root = insertNode(root,a);
    }
    cout<<isPalindrome(root);
}
