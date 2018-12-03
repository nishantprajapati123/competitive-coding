#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        bool found = false;
        int pos,pos_small;
        string w;
        getline(cin,w);
        int n=w.length();
//        cout<<n<<endl;
        for(int i=n-1;i>0;i--)
        {
            if(w[i]>w[i-1])
            {
                pos=i-1;
                found = true;
                break;
            }
        }
        if(found)
        {
//            cout<<pos<<endl;
            for(int i=n-1;i>pos;i--)
            {
//                cout<<n<<endl;
//                cout<<i<<endl;
//                 cout<<w[i];
                if(w[i]>w[pos])
                {
                    //cout<<n<<endl;
                    pos_small=i;
                    break;

                }

            }
//            cout<<pos_small<<endl;
            swap(w[pos],w[pos_small]);
//            char temp=w[pos];
//            w[pos]=w[pos_small];
//            w[pos_small]=temp;
            reverse(w.begin()+pos+1,w.end());
            cout<<w<<endl;
        }
        else
            cout<<"no answer"<<endl;

    }
}
