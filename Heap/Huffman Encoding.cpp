#include<bits/stdc++.h>
using namespace std;
struct heapNode
{
    char alpha; //one input
    int freq;
    heapNode *left, *right;//left ,right child
    heapNode(char alpha, int freq)
    {
        this->alpha=alpha;
        this->left=this->left=NULL;
        this->freq=freq;
    }
};
//create comparator for min heap
struct comparator
{
    bool operator()(heapNode *l, heapNode *r)
    {
        return (l->left > l->right);
    }
};
class Node
{
    //heapNode *temp;
public:
    void print(heapNode *root, string str);
    void huffmanCode(string data, vector<int>freq, int siz);
};
void Node::huffmanCode(string data, vector<int>freq,int siz)
{
    heapNode *left,*right,*top;
    //make min heap
    priority_queue<heapNode*,vector<heapNode*>,comparator>minHeap;
    //push all data with corresponding frequency in min heap
    for(int i=0;i<siz;i++)
        minHeap.push(new heapNode(data[i],freq[i]));

    //loop till heap length is 1
    while(minHeap.size()!=1)
    {
        //extract two minimum node
        left=minHeap.top();minHeap.pop();
        right=minHeap.top();minHeap.pop();
        //create new node freq= sum of freq(left+right)
        //add new node into min heap with special character @
        top=new heapNode('@',(left->freq+right->freq));
        //join the left and right node to its left and right child
        top->left=left;
        top->right=right;
        minHeap.push(top);
    }
    print(minHeap.top(),"");
}
void Node::print(heapNode *root, string str)
{
    if(!root)
        return ;
    if(root->alpha!='@')
        cout<<root->alpha<<":"<<str<<endl;
    print(root->left,str+"0");
    print(root->right,str+"1");
}
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string data;
        vector<int>freq;
        getline(cin,data);
        for(int i=0;i<data.length();i++)
        {
            int a;
            cin>>a;
            freq.push_back(a);
        }
        Node n;
        n.huffmanCode(data,freq,data.length());
        cout<<endl;
    }
}
