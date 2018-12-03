#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
int main()
{
    long int t;
    cin>>t;
    while(t--)
    {
        long int px,py,pz,qx,qy,qz,dx,dy,dz,cx,cy,cz,r;
        double A,B,C,D,m2,m21,m22,t,t1,t2;
        cin>>px>>py>>pz>>qx>>qy>>qz>>dx>>dy>>dz>>cx>>cy>>cz>>r;
        A=pow((cx+px),2)-pow(r,2);
        B=2*(cx+px)*(cy+py);
        C=pow((cy+py),2)-pow(r,2);
        if(A!=0)
        {
            D=(B*B)-(4*A*C);
            m21=((-B)+sqrt(D))/(2*A);
            m22=((-B)+sqrt(D))/(2*A);
            t1=((m21*px)-py+qy-(m21*qx))/((m21*dx)-dy);
            t2=((m22*px)-py+qy-(m22*qx))/((m22*dx)-dy);
            t=min(t1,t2);
        }
        else{
            m2=C/B;
            t=((m2*px)-py+qy-(m2*qx))/((m2*dx)-dy);

        }
        cout<<setprecision(10)<<fixed<<t<<endl;
    }
}
