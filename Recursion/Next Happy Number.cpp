#include<bits/stdc++.h>
using namespace std;
bool happyNo(int num)
{
    int no=num;
    int sum=0;
    while(no>0)
    {
        int rem=no%10;
        sum+=(rem*rem);
        no=no/10;
    }
    if(sum==1)
        return true;
    else if(sum>1 && sum<10)
        return false;
    else
        return happyNo(sum);

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int num;
        cin>>num;
        int n=num+1;
        while(!happyNo(n))
        {
            n++;
        }
        cout<<n<<endl;
    }
}
