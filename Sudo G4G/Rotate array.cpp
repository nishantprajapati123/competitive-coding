#include<bits/stdc++.h>
using namespace std;
int main()
 {
    int t;
	cin>>t;
	while(t--)
	{
	    int n,d;
	    cin>>n>>d;
	    queue<int>q;
	    for(int i=1;i<=n;i++)
	    {
	        int a;
	        cin>>a;
	        q.push(a);
	    }
	    for(int i=1;i<=d;i++)
	    {
	        int ele=q.front();
	        q.pop();
	        q.push(ele);
	    }
	    while(!q.empty())
	    {
	        cout<<q.front()<<" ";

	        q.pop();
	    }
	    cout<<endl;
	}
}
