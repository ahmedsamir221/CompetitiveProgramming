//https://codeforces.com/blog/entry/55362
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
const int N =300005;

int n,t[N],id[N],c,tt[N],r[N];
vector<int>a[N],b[N];

void go(int u)
{
    id[u]=++c;
    tt[id[u]]=t[u];
    for(auto v:b[u])
    {
        go(v);
        a[id[u]].push_back(id[v]);
    }
}

void dfs(int u)
{
    for(auto v:a[u])
    {
        dfs(v);
        r[u]=max(r[u],r[v]);
    }
    r[u]=max(r[u],u);
}

int val[20*N],laz[20*N];
int bulid(int s=1,int e=n,int p=1)
{
    if(s==e)return val[p]=tt[s];
    int mid=(s+e)/2;
    return val[p]=bulid(s,mid,p*2)+bulid(mid+1,e,p*2+1);
}

void lazy(int s,int e,int p)
{
    int mid=(s+e)/2;
    val[p*2]=(mid-s+1)-val[p*2];
    val[p*2+1]=(e-mid)-val[p*2+1];
    laz[p*2]=!laz[p*2];
    laz[p*2+1]=!laz[p*2+1];
    laz[p]=0;
}

int up(int s,int e,int p,int l,int r)
{
    if(s>=l&&e<=r)
    {
        laz[p]=!laz[p];
        return val[p]=(e-s+1)-val[p];
    }
    if(laz[p])lazy(s,e,p);
    int mid=(s+e)/2;
    if(r<=mid)return val[p]=up(s,mid,p*2,l,r)+val[p*2+1];
    else if(l>mid)return val[p]=val[p*2]+up(mid+1,e,p*2+1,l,r);
    else return val[p]=up(s,mid,p*2,l,r)+up(mid+1,e,p*2+1,l,r);
}

int get(int s,int e,int p,int l,int r)
{
    if(s>=l&&e<=r) return val[p];
    if(laz[p])lazy(s,e,p);
    int mid=(s+e)/2;
    if(r<=mid)return get(s,mid,p*2,l,r);
    else if(l>mid)return get(mid+1,e,p*2+1,l,r);
    else return get(s,mid,p*2,l,r)+get(mid+1,e,p*2+1,l,r);
}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;

     cin>>n;
     int p;
     forr(i,2,n)
     {
         cin>>p;
         b[p].push_back(i);
     }
     forr(i,1,n)cin>>t[i];
     go(1);
     dfs(1);
     bulid();
     int q,x;
     string s;
     cin>>q;
     while(q--)
     {
         cin>>s>>x;
         int i=id[x];
         if(s=="get")cout<<get(1,n,1,i,r[i])<<endl;
         else up(1,n,1,i,r[i]);
     }



return 0;
}
