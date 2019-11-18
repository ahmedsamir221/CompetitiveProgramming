/*
   if we cut some vertex from the tree , the best for us to find an edge that will split the remaining tree
   to two half win min difference in size .
   so we will try from the all nodes to cut it from the tree and lower bound on the remaining tree sizes
   to find the optimal edge , then minimize the answer .
   */
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
const int N = 2e5 + 3, M = 5e4 + 3;
int n,sz[N],ans=1e9;
vector<int>a[N];
multiset<int>m,s;
void dfs(int u,int p)
{
    for(auto v:a[u])
    {
        if(v==p)continue;
        dfs(v,u);
        sz[u]+=sz[v];
    }
    sz[u]++;
}

void get(int u,int p)
{
    m.erase(m.lower_bound(sz[u]));
    s.insert(sz[u]);
    for(auto v:a[u])
    {
        if(v==p)continue;
        get(v,u);
    }
    if(p==-1)return;
    s.erase(s.lower_bound(sz[u]));
    int rem=n-sz[u];
    int mid=rem/2;
    auto it=m.upper_bound(mid);
    if(it!=m.end())
    {
        int k=*it;
        if(k>=sz[u])ans=min(ans,max(rem-k,k)-min(sz[u],rem-k));
    }
    if(it!=m.begin())
    {
        it--;
        int k=*it;
        if(k>=sz[u])ans=min(ans,max(rem-k,k)-min(sz[u],rem-k));
    }
    it=s.upper_bound(sz[u]+mid);
    if(it!=s.end())
    {
        int k=*it;
        int mn=min(n-k,min(k-sz[u],sz[u]));
        int mx=max(n-k,max(k-sz[u],sz[u]));
        ans=min(ans,mx-mn);
    }
    if(it!=s.begin())
    {
        it--;
        int k=*it;
        int mn=min(n-k,min(k-sz[u],sz[u]));
        int mx=max(n-k,max(k-sz[u],sz[u]));
        ans=min(ans,mx-mn);
    }
    m.insert(sz[u]);
}

 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;
       cin>>n;
       int u,v;
       forr(i,1,n-1)
       {
           cin>>u>>v;
           a[u].push_back(v);
           a[v].push_back(u);
       }
       dfs(1,-1);
       forr(i,1,n)m.insert(sz[i]);
       get(1,-1);
       cout<<ans<<endl;



return 0;
}
