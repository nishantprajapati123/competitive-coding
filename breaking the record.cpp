#include<bits/stdc++.h>
using namespace std;
struct result
{
    int high=0;
    int worse=0;
}r;
result breakTheRecord(int n)
{

    int max_s,min_s,score;
    for(int i=0;i<n;i++)
    {

        cin>>score;
        if(i==0)
            max_s=min_s=score;
        if(score>min_s && score>max_s)
        {
            max_s=score;

            r.high+=1;
        }

        else if(score<max_s && score<min_s)
        {
            min_s=score;
            r.worse+=1;
        }
        else
            score=0;

    }
    return r;

}
int main()
{
    int n;
    cin>>n;
    breakTheRecord(n);
    cout<<r.high<<" "<<r.worse;
    return 0;
}
