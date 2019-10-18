//https://discuss.codechef.com/t/robagain-editorial/20734
#pragma GCC optimize("O3")
#include<queue>
#include <cmath>
#include <complex>
#include<map>
#include <string>
#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <stdio.h>
#include<bits/stdc++.h>


/*
#define x real()
#define y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))
*/

//#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);
#define NOT(x) (1^x)

const double PI  = acos(-1.0);
using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
typedef complex<double> point;

//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//const int N=500009,M=1000000;
const double EPS= 1e-9,eps=-1e9;
const int N =50005;
int n,head[N*2+9],nxt[N*20*8+9],to[N*20*8+9],ne;
void init()
{
    memset(head,-1,n*sizeof head[0]);
    ne=0;
}
void addedge(int f,int t)
{
    to[ne]=t;
    nxt[ne]=head[f];
    head[f]=ne++;
}
int lo[N*2+9],vis[N*2+9],curt,compid[N*2+9],comps;
stack<int>sk;
void tarjan(int u)
{
    vis[u]=lo[u]=curt++;
    sk.push(u);
    for(int e=head[u];~e;e=nxt[e])
    {
        int v=to[e];
        if(vis[v]==-1)
        {
            tarjan(v);
            lo[u]=min(lo[u],lo[v]);
        }
        else if(compid[v]==-1)
            lo[u]=min(lo[u],lo[v]);
    }
    if(lo[u]==vis[u])
    {
        int p;
        do{
            p=sk.top();
            sk.pop();
            compid[p]=comps;
        }while(p!=u);
        comps++;
    }
}
string s;
void go()
{
    memset(vis,-1,n*sizeof vis[0]);
    memset(compid,-1,n*sizeof compid[0]);
    comps=curt=0;
    forr(i,0,n-1)
    if(vis[i]==-1&&s[i/2]!='.')tarjan(i);
}
int ck[22][22][2][2],idd;
int get(int a,int b,int da,int db)
{
    idd++;
    int la=max(0,a-s[a]+'0'),ra=min((int)s.size()-1,a+s[a]-'0');
    int lb=max(0,b-s[b]+'0'),rb=min((int)s.size()-1,b+s[b]-'0');
    while(1){
        if(a==la&&da==-1)da=1;
        if(a==ra&&da==1)da=-1;
        if(b==lb&&db==-1)db=1;
        if(b==rb&&db==1)db=-1;
        if(la!=ra)a+=da;
        if(lb!=rb)b+=db;
        if(a==b)return 0;
        if(ck[a-la][b-lb][(da==-1?0:1)][(db==-1?0:1)]==idd)break;
        ck[a-la][b-lb][(da==-1?0:1)][(db==-1?0:1)]=idd;
    }
    return 1;
}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;
  int t;
  cin>>t;
  while(t--)
  {
      cin>>s;
      int m=s.size();
      n=m*2;
      init();
      for(int i=0;i<m;i++)
      {
          if(s[i]=='.')continue;
          for(int j=i+1;j<min(m,i+19);j++)
          {
               if(s[j]=='.')continue;
               if(j-i-1<s[i]-'0'+s[j]-'0')
               {
                   if(get(i,j,-1,-1)==0)addedge(NOT(i*2),j*2),addedge(j*2,NOT(i*2));
                   if(get(i,j,1,1)==0)addedge(i*2,NOT(j*2)),addedge(NOT(j*2),i*2);
                   if(get(i,j,-1,1)==0)addedge(NOT(i*2),NOT(j*2)),addedge(NOT(j*2),NOT(i*2));
                   if(get(i,j,1,-1)==0)addedge(i*2,j*2),addedge(j*2,i*2);
               }
          }
      }

      go();
      int ff=1;
      for(int i=0;i<m;i++)
      {
          if(s[i]=='.')continue;
          if(compid[i*2]==compid[NOT(i*2)])ff=0;
      }
      if(ff)cout<<"safe"<<endl;
      else cout<<"unsafe"<<endl;

  }


return 0;
}
