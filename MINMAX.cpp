#include<iostream>
using namespace std;
struct check
{
	int min;
	int max;
}c,c1,c2;
/*int MIN(int x, int y)
{
	if(x<y)
	  return x;
	else 
	return y;  
}
int MAX(int x ,int y)
{
	if(x>y)
	  return x;
	else
	  return y;
}*/
check MINMAX(int a[],int low, int n)
{
	int mid;
	if(low==n)
	{
		c.min=c.max=a[low];
		return c;
	}
	else if(low==n+1)
	{
		if(a[low]<a[n])
		{
		  c.min=a[low];
		  c.max=a[n];
	    }
	    else
	    {
	    	c.min=a[n];
	    	c.min=a[low];
		}
		return c;
	}
	else
	{
		mid=(low+n)/2;
		c1=MINMAX(a,low,mid);
		c2=MINMAX(a,mid+1,n);
		if(c1.min<c2.min)
		    c.min=c1.min;
		else
		    c.min=c2.min;
		if(c1.max>c2.max)
		    c.max=c1.max;
	    else
	        c.max=c2.max;
	
	  return c;
	}
	
}


int main()
{
	int a[]={9,6,4,5,2,7};
	MINMAX(a,0,5);
	cout<<"Minimum:"<<c.min<<endl;
	cout<<"Maximum:"<<c.max;
	return 0;
	
}
