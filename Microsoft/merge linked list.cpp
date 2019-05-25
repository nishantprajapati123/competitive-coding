#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
node* insertNode(int key)
{
    node* temp=new node;
    temp->data=key;
    temp->next=NULL;
    return temp;
}
/*void print(node *head)
{
    node *t=head;
    while(t)
    {
        cout<<t->data<<" ";
        t=t->next;
    }
}*/
node* mergeNode(node *headA, node *headB)
{
    node *p,*q,*head;
    p=headA;
    q=headB;
    node* s=NULL;
    if(p==NULL)
        return q;
    if(q==NULL)
        return p;
    if(p && q)
    {
    if(p->data < q->data)
    {
        s=p;
        head=p;
        p=s->next;

    }
    else
    {
        head=q;
        s=q;
//        q->next=p;
        q=s->next;
    }
    }
    while(p&&q)
    {
        if(p->data < q->data)
        {
            s->next = p;
            s=p;
//            p->next=q;
            p=s->next;
        }
        else
        {
            s->next = q;
            s=q;
//            q->next=p;
            q=s->next;
        }
//        cout<<"ok"<<endl;

    }
    if(p)
    {
        s->next=p;
    }
    else
        s->next=q;

    return head;
}
int main()
{
    node *head;
    node* headA= insertNode(1);
    headA->next= insertNode(3);
    headA->next->next = insertNode(5);


    node* headB =insertNode(2);
    headB->next=insertNode(4);
    headB->next->next=insertNode(6);
    head= mergeNode(headA,headB);


//    cout<<"OK";
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
