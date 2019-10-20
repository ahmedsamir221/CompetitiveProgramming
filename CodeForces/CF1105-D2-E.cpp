//https://codeforces.com/blog/entry/64664
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
const int N =100005;

int n,m,ans,vid,vis[N];
vector<int>a[50];
int ck[50][50];
map<string,int>id;
ll msk[50];
int get(int s,int t)
{
    vid++;
    for(auto p:a[s])vis[p]=vid;
    for(auto p:a[t])if(vis[p]==vid)return 1;
    return 0;
}
int mem[21][1<<21];
int go(int i,int k)
{
    if(i==m-m/2)return 0;
    int&ret=mem[i][k];
    if(~ret)return ret;
    ret=0;
    if(k&(1<<i)) ret=max(ret,go(i+1,k));
    else{
        ret=max(ret,go(i+1,k|(msk[i+m/2]>>m/2))+1);
        ret=max(ret,go(i+1,k));
    }
    return ret;
}
void can(int k)
{
    int t=0;
    ll v=0;
    for(int i=0;i<m/2;i++)
    {
        if(k&(1<<i)){
          t++;
          v|=msk[i];
          for(int j=i+1;j<m/2;j++)
          {
              if(k&(1<<j))
              {
                  if(ck[i][j])return;

              }
          }
        }
    }
    v=(v>>m/2);
    ans=max(ans,t+go(0,v));
}

int xx[1000007];
string ss[1000007];
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;

     cin>>n>>m;
     int c=0,x,t=0;
     string s;
     forr(i,1,n)
     {
         cin>>xx[i];
         if(xx[i]==1)continue;
         else{
            cin>>ss[i];
            if(id.count(ss[i])==0)id[ss[i]]=t++;
         }
     }
     forr(i,1,n)
     {
         if(xx[i]==1)c++;
         else{
            a[id[ss[i]]].push_back(c);
         }
     }
     for(int i=0;i<m;i++)
     {
         for(int j=i+1;j<m;j++)
         {
             if(i==j)continue;
             ck[i][j]=get(i,j);
             ck[j][i]= ck[i][j];
         }
     }
    for(int i=0;i<m;i++)
     {
         for(int j=i+1;j<m;j++)
         {
             if(i==j)continue;
             if(ck[i][j])msk[i]|=((ll)1<<j);
         }
     }
     memset(mem,-1,sizeof mem);
     for(int i=0;i<(1<<m/2);i++)
     {
          can(i);
     }
     cout<<ans;




return 0;
}
