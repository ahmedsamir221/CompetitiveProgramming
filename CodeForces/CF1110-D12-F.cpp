//https://codeforces.com/blog/entry/65079
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
const int N=500007,M=1000000;
const double EPS= 1e-9,eps=-1e9;

int n,q,num[N],c,mxleaf[N];
ll dis[N],val[N*20],laz[N*20],a[N],ans[N];
vector<pair<int,int>>adj[N];
vector<pair<int,pair<int,int>>>qlist[N];
void dfs(int u)
{
    num[u]=++c;
    for(auto v:adj[u])
    {
        dis[v.F]=dis[u]+(ll)v.S;
        dfs(v.F);
        mxleaf[u]=max(mxleaf[u],mxleaf[v.F]);
    }
    if((int)adj[u].size()==0)a[num[u]]=dis[u];
    else a[num[u]]=4e18;
    mxleaf[u]=max(mxleaf[u],num[u]);
}

ll bulid(int s=1,int e=n,int p=1)
{
    if(s==e)return val[p]=a[s];
    int mid=(s+e)/2;
    return val[p]=min(bulid(s,mid,p*2),bulid(mid+1,e,p*2+1));
}

void lazy(int p)
{
    val[p*2]+=laz[p];
    laz[p*2]+=laz[p];
    val[p*2+1]+=laz[p];
    laz[p*2+1]+=laz[p];
    laz[p]=0;
}

ll up(int s,int e,int p,int l,int r,int v)
{
    if(s>e||l>r)return 0;
    if(s>=l&&e<=r)
    {
        laz[p]+=v;
        val[p]+=v;
        return val[p];
    }
    lazy(p);
    int mid=(s+e)/2;
    if(r<=mid)return val[p]=min(up(s,mid,p*2,l,r,v),val[p*2+1]);
    else if(l>mid) return val[p]=min(val[p*2],up(mid+1,e,p*2+1,l,r,v));
    else return val[p]=min(up(s,mid,p*2,l,r,v),up(mid+1,e,p*2+1,l,r,v));
}

ll query(int s,int e,int p,int l,int r)
{
    if(s>e||l>r)return 0;
    if(s>=l&&e<=r)return val[p];
    lazy(p);
    int mid=(s+e)/2;
    if(r<=mid)return query(s,mid,p*2,l,r);
    else if(l>mid) return query(mid+1,e,p*2+1,l,r);
    else return min(query(s,mid,p*2,l,r),query(mid+1,e,p*2+1,l,r));
}

void get(int u)
{
    for(auto p:qlist[u])
        ans[p.F]=query(1,n,1,p.S.F,p.S.S);
    for(auto v:adj[u])
    {
       up(1,n,1,num[v.F],mxleaf[v.F],-v.S);
       up(1,n,1,1,num[v.F]-1,v.S);
       up(1,n,1,mxleaf[v.F]+1,n,v.S);
       get(v.F);
       up(1,n,1,num[v.F],mxleaf[v.F],v.S);
       up(1,n,1,1,num[v.F]-1,-v.S);
       up(1,n,1,mxleaf[v.F]+1,n,-v.S);
    }
}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;


    cin>>n>>q;
    int p,w;
    forr(i,2,n)
    {
        cin>>p>>w;
        adj[p].push_back({i,w});
    }
    dfs(1);
    bulid();
    int v,l,r;
    forr(i,1,q)
    {
        cin>>v>>l>>r;
        qlist[v].push_back({i,{l,r}});
    }
    get(1);
    forr(i,1,q)cout<<ans[i]<<endl;


return 0;
}
