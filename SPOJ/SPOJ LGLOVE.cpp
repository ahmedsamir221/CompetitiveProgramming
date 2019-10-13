//https://github.com/tanmoy13/CompetitveProgramming/blob/master/Online-Judge-Solutions/SPOJ/LGLOVE%20-%20LCM%20GCD%20Love.cpp
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

#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);


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
const int N =300005;
struct node{
    int mn=1e9,mx=-1;
};
int n,q;
ll a[N],laz[N*20];
ll lcm[N+4],mod=1e9+7;
node val[N*20];
int ck[N],cnt[N];

long long fpower (long long a, long long p, long long m)
{
    long long res = 1 % m, x = a % m;
    while (p>0)
    {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m;
        p >>= 1;
    }
    return res;
}
int c[N];
void init()
{
    forr(i,2,N-1)
        if(ck[i]==0)
            for(int j=i;j<=N-1;j+=i)ck[j]=i;
    ll x=1;
    lcm[1]=1;
    forr(i,2,N-1)
    {
        int g=i;
        vector<int>v;
        while(g>1)
        {
            c[ck[g]]++;
            v.push_back(ck[g]);
            g/=ck[g];
        }
        for(auto p:v)
        {
            if(c[p]==0)continue;
            if(c[p]>cnt[p])
            {
                x=(x*fpower((ll)p,(ll)(c[p]-cnt[p]),mod))%mod;
                cnt[p]=c[p];
                c[p]=0;
            }
            else c[p]=0;
        }
        lcm[i]=x;
    }

}
void bulid(int s=1,int e=n,int p=1)
{
    if(s==e)
    {
        val[p].mn=a[s];
        val[p].mx=a[s];
        return ;
    }
    int mid=(s+e)/2;
    bulid(s,mid,p*2);
    bulid(mid+1,e,p*2+1);

    val[p].mx=max(val[p*2].mx,val[p*2+1].mx);
    val[p].mn=min(val[p*2].mn,val[p*2+1].mn);

}

void lazy(int p)
{
    val[p*2].mn+=laz[p];
    val[p*2].mx+=laz[p];
    val[p*2+1].mn+=laz[p];
    val[p*2+1].mx+=laz[p];
    laz[p*2]+=laz[p];
    laz[p*2+1]+=laz[p];
    laz[p]=0;
}

void up(int s,int e,int p,int l,int r,int v)
{
    if(s>=l&&e<=r)
    {
        laz[p]+=v;
        val[p].mn+=v;
        val[p].mx+=v;
        return ;
    }
    if(laz[p])lazy(p);
    int mid=(s+e)/2;
    if(r<=mid) up(s,mid,p*2,l,r,v);
    else if(l>mid) up(mid+1,e,p*2+1,l,r,v);
    else {
        up(s,mid,p*2,l,r,v);
        up(mid+1,e,p*2+1,l,r,v);
    }
    val[p].mx=max(val[p*2].mx,val[p*2+1].mx);
    val[p].mn=min(val[p*2].mn,val[p*2+1].mn);

}

node get(int s,int e,int p,int l,int r)
{
    if(s>=l&&e<=r)return val[p];
    if(laz[p])lazy(p);
    int mid=(s+e)/2;
    if(r<=mid) return get(s,mid,p*2,l,r);
    else if(l>mid) return get(mid+1,e,p*2+1,l,r);
    else {
        node c1=get(s,mid,p*2,l,r);
        node c2=get(mid+1,e,p*2+1,l,r);
        node c;
        c.mx=max(c1.mx,c2.mx);
        c.mn=min(c1.mn,c2.mn);
        return c;
    }
}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;
      init();
      scanf("%d%d",&n,&q);
      forr(i,1,n)scanf("%d",&a[i]);
      bulid();
      int t,l,r,p;
      while(q--)
      {
          scanf("%d%d%d",&t,&l,&r);
          l++,r++;
          if(t==0)
          {
              scanf("%d",&p);
              up(1,n,1,l,r,p);
          }
          else if(t==1)
          {
              node k=get(1,n,1,l,r);
              printf("%lld\n",lcm[k.mx]);
          }
          else
          {
              node k=get(1,n,1,l,r);
              printf("%lld\n",lcm[k.mn]);
          }
      }

return 0;
}
