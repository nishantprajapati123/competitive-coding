#include<iostream>
#include<math.h>
using namespace std;
int power(int a,int n)
{
	if(n==1)
	   return 2;
    else if(n==0)
       return 1;
    else
      return 2*power(a,n-1);
}
int main()
{
	cout<<"power="<<power(2,5);
	return 0;
}

