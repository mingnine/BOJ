#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
void go(int n,int x,int y)
{
    if(n==0) return;
    go(n-1,x,6-x-y);
    cout<<x<<' '<<y<<'\n';
    go(n-1,6-x-y,y);
}
 
void cnt(int n)
{
    string s="1";
    while(n--)
    {
        int up=0;
        for(int i=0;i<s.size();i++)
        {
            int d=(s[i]-'0')*2+up;
            if(d<10) s[i]=d+'0',up=0;
            else s[i]=d%10+'0',up=d/10;
        }
        if(up) s+=up+'0';
    }
    if(s[0]!='0') s[0]--;
    else
    {
        s[0]='9';
        for(int i=1;i<s.size();i++)
            if(s[i]!='0') { s[i]--; break; }
    }
    reverse(s.begin(),s.end());
    cout<<s<<'\n';
}
 
int main()
{
    int n;
    cin>>n;
    cnt(n);
    if(n<=20) go(n,1,3);
    return 0;
}
