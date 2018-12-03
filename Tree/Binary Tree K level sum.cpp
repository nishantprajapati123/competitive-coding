#include<bits/stdc++.h>
using namespace std;
void sumKLevel(string tree,int k)
{
    stack<char>s;
    map<int,vector<int> >m;
    int j=0,i=1;
    s.push(tree[0]);
    while(!s.empty())
    {
        if(tree[i]=='(')
        {
            s.push(tree[i]);
            j=j+1;
            cout<<tree[i]<<" "<<j<<" "<<i<<endl;
        }
        else if(tree[i]==')')
        {
            s.pop();
            j=j-1;
            cout<<tree[i]<<" "<<j<<" "<<i<<endl;
        }
        else
        {
            m[j].push_back(tree[i]);
            cout<<tree[i]<<" "<<j<<" "<<i<<endl;
        }
        i++;
    }
    int sum=0;
    map<int,vector<int> >::iterator it;
    //for(it=m[k].begin();it!=m[k].end();++it)
      //  sum+=(*it);
    for(it=m.begin();it!=m.end();++it)
    {
        //if(it->first==k)
        {
            for(int i=0;i<it->second.size();i++)
                cout<<it->second[i]<<" ";
        }

    }
}
int main()
{
    int t;
    cin>>t;
    //cin.ignore();
    while(t--)
    {
        int k;
        string tree;
        cin>>k;
        cin.ignore();
        getline(cin,tree);
        sumKLevel(tree,k);
    }

}
