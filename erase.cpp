#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    cout<<s[s.length()-1];
    cout<<s.length();
    s.erase(3,2);
    cout<<s;
}
