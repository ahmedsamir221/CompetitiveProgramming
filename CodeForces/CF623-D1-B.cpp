//http://codeforces.com/blog/entry/23278
#include <iostream>
#include<vector>
#include<algorithm>
//#include <cmath>
//#include <complex>
#include<queue>
#include<map>
#include <string>
#include<bits/stdc++.h>
#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);
//#define x real()
//#define y imag()
using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
//typedef complex<double> point;
//template<typename T>T gcd(T x, T y) { if(y == 0)return x; else return gcd(y, x%y); }
//typedef bitset<30> mask;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//const double PI = acos(-1.0);
//const double EPS = 1e-9;
//typedef complex<double> point;
int n,v[1000005],a,b;
ll mem[3][1000005],ansl=1e18,ansr=1e18;
vector<int>s,e;
map<int,int>vs,ve;

ll dpl(int p,int ck,int i)
{
    if(i>n)return 0;
    ll&ret=mem[ck][i];
    if(~ret)return ret;
    ret=1e16;
    int g=-1;
    if(v[i]%s[p]==0)g=0;
    else if((v[i]+1)%s[p]==0||(v[i]-1)%s[p]==0)g=1;

    if(ck==0)
    {
       if(g>-1)
       ret=min(ret,dpl(p,ck,i+1)+(ll)g*(ll)b);

       ret=min(ret,dpl(p,1,i+1)+(ll)a);
    }
    else if(ck==1)
    {
       if(g>-1)
       ret=min(ret,dpl(p,2,i+1)+(ll)g*(ll)b);

       ret=min(ret,dpl(p,1,i+1)+(ll)a);
    }
    else if(g>-1)
        ret=min(ret,dpl(p,ck,i+1)+(ll)g*(ll)b);

    return ret;
}

ll dpr(int p,int ck,int i)
{
    if(i==n)return 0;
    ll&ret=mem[ck][i];
    if(~ret)return ret;
    ret=1e16;
    int g=-1;
    if(v[i]%e[p]==0)g=0;
    else if((v[i]+1)%e[p]==0||(v[i]-1)%e[p]==0)g=1;

    if(ck==0)
    {
       if(g>-1)
       ret=min(ret,dpr(p,ck,i+1)+(ll)g*(ll)b);

       ret=min(ret,dpr(p,1,i+1)+(ll)a);
    }
    else if(ck==1)
    {
       if(g>-1)
       ret=min(ret,dpr(p,2,i+1)+(ll)g*(ll)b);

       ret=min(ret,dpr(p,1,i+1)+(ll)a);
    }
    else if(g>-1)
        ret=min(ret,dpr(p,ck,i+1)+(ll)g*(ll)b);

    return ret;
}
int main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
cin>>n>>a>>b;
forr(i,1,n)cin>>v[i];

int g=v[1];
forr(i,2,sqrt(g))
{
    if(g%i==0)
    {
        s.push_back(i);
        vs[i]=1;
        while(g%i==0)g/=i;
    }
}
if(g>1)s.push_back(g);

 g=v[1]+1;
forr(i,2,sqrt(g))
{
    if(g%i==0)
    {
        if(vs.count(i)==0)
        s.push_back(i),vs[i]=1;
        while(g%i==0)g/=i;
    }
}
if(g>1)s.push_back(g);

 g=v[1]-1;
forr(i,2,sqrt(g))
{
    if(g%i==0)
    {
        if(vs.count(i)==0)
        s.push_back(i),vs[i]=1;
        while(g%i==0)g/=i;
    }
}
if(g>1)s.push_back(g);


g=v[n];
forr(i,2,sqrt(g))
{
    if(g%i==0)
    {
        e.push_back(i);
        while(g%i==0)g/=i;
    }
}
if(g>1)e.push_back(g);

g=v[n]+1;
forr(i,2,sqrt(g))
{
    if(g%i==0)
    {
        if(ve.count(i)==0)
        e.push_back(i),ve[i]=1;
        ve[i]=1;
        while(g%i==0)g/=i;
    }
}
if(g>1)e.push_back(g);


g=v[n]-1;
forr(i,2,sqrt(g))
{
    if(g%i==0)
    {
        if(ve.count(i)==0)
        e.push_back(i),ve[i]=1;
        while(g%i==0)g/=i;
    }
}
if(g>1)e.push_back(g);


forr(i,0,(int)s.size()-1)
{
memset(mem,-1,sizeof mem);
if(v[1]%s[i]==0)
ansl=min(ansl,dpl(i,0,2));
else
ansl=min(ansl,dpl(i,0,2)+b);
}


forr(i,0,(int)e.size()-1)
{
memset(mem,-1,sizeof mem);
if(v[n]%e[i]==0)
ansr=min(ansr,dpr(i,0,1));
else
ansr=min(ansr,dpr(i,0,1)+b);
}


cout<<min(ansl,ansr);

return 0;
}
