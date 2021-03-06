//https://codeforces.com/blog/entry/22936
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
const int N=500009,M=1000000;
const double EPS= 1e-9,eps=-1e9;
int n,q,id[N],c[N],nc[N],mx[N],e;
ll val[N*20],laz[N*20];
vector<int>adj[N];

void dfs(int u,int p)
{
    id[u]=++e;
    nc[id[u]]=c[u];
    for(auto v:adj[u])
    {
        if(v==p)continue;
        dfs(v,u);
        mx[id[u]]=max(mx[id[v]],mx[id[u]]);
    }
    mx[id[u]]=max(id[u],mx[id[u]]);
}

ll bulid(int s=1,int e=n,int p=1)
{
    if(s==e)return val[p]=((ll)1<<nc[s]);
    int mid=(s+e)/2;
    return val[p]=bulid(s,mid,p*2)|bulid(mid+1,e,p*2+1);
}
void lazy(int p)
{
    val[p*2]=laz[p];
    laz[p*2]=laz[p];
    val[p*2+1]=laz[p];
    laz[p*2+1]=laz[p];
    laz[p]=0;
}

ll up(int s,int e,int p,int l,int r,ll v)
{
    if(s>=l&&e<=r){
        laz[p]=v;
        return val[p]=v;
    }
    if(laz[p])lazy(p);
    int mid=(s+e)/2;
    if(r<=mid)return val[p]=up(s,mid,p*2,l,r,v)|val[p*2+1];
    else if(l>mid)return val[p]=val[p*2]|up(mid+1,e,p*2+1,l,r,v);
    else return val[p]=up(s,mid,p*2,l,r,v)|up(mid+1,e,p*2+1,l,r,v);
}

ll get(int s,int e,int p,int l,int r)
{
    if(s>=l&&e<=r)return val[p];
    if(laz[p])lazy(p);
    int mid=(s+e)/2;
    if(r<=mid)return get(s,mid,p*2,l,r);
    else if(l>mid)return get(mid+1,e,p*2+1,l,r);
    else return get(s,mid,p*2,l,r)|get(mid+1,e,p*2+1,l,r);
}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;

   cin>>n>>q;
   forr(i,1,n)cin>>c[i],c[i]--;
   int u,v;
   forr(i,1,n-1)
   {
       cin>>u>>v;
       adj[u].push_back(v);
       adj[v].push_back(u);
   }
   dfs(1,-1);
   bulid();
   int t,node;
   ll color;
   while(q--)
   {
       cin>>t;
       if(t==1)
       {
           cin>>node>>color;
           color--;
           up(1,n,1,id[node],mx[id[node]],(ll)1<<color);
       }
       else
       {
           cin>>node;
           cout<<__builtin_popcountll(get(1,n,1,id[node],mx[id[node]]))<<endl;
       }
   }



return 0;
}
