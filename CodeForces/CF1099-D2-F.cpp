//https://codeforces.com/blog/entry/64331
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
const int N=1000009,M=1000000;
const double EPS= 1e-9,eps=-1e9;
ll n,x[100007],t[100007];
ll T,val[N*23],sum[N*23];
vector<pair<int,int>>adj[100007];

void up(int s,int e,int p,int idx,int v,int typ)
{
    if(s==e)
    {
        val[p]+=(ll)idx*(ll)v*(ll)typ;
        sum[p]+=v*(ll)typ;
        return ;
    }
    int mid=(s+e)/2;
    if(idx<=mid)up(s,mid,p*2,idx,v,typ);
    else up(mid+1,e,p*2+1,idx,v,typ);

    val[p]=val[p*2]+val[p*2+1];
    sum[p]=sum[p*2]+sum[p*2+1];
}
pii getsum(int s,int e,int p,int l,int r)
{
    if(l>r)return {0,0};
    if(s>=l&&e<=r)return {val[p],sum[p]};
    int mid=(s+e)/2;
    if(r<=mid)return getsum(s,mid,p*2,l,r);
    else if(l>mid) return getsum(mid+1,e,p*2+1,l,r);
    else {
            pii c1=getsum(s,mid,p*2,l,r);
            pii c2=getsum(mid+1,e,p*2+1,l,r);
            return {c1.F+c2.F,c1.S+c2.S};
    }
}

int getid(int s,int e,int p,ll k)
{
    if(s==e)return s;
    int mid=(s+e)/2;
    if(val[p*2]<=k)return getid(mid+1,e,p*2+1,k-val[p*2]);
    else return getid(s,mid,p*2,k);

}

ll get(int u,ll k)
{
    if(k*2>=T)return 0;
    up(1,1000000,1,t[u],x[u],1);
    int idx=getid(1,1000000,1,T-k*2);
    pii g=getsum(1,1000000,1,1,idx-1);
    ll nodeans=g.S+min((T-k*2-g.F)/(ll)idx,getsum(1,1000000,1,idx,idx).S);
   //cout<<u<<" "<<nodeans<<" "<<idx<<" "<<g.F<<" "<<g.S<<endl;
    vector<ll>ans;
    for(auto v:adj[u])
        ans.push_back(get(v.F,k+v.S));
    up(1,1000000,1,t[u],x[u],-1);
    sort(ans.rbegin(),ans.rend());
    if(u==1) return max(nodeans,ans[0]);
    else if((int)ans.size()<=1||nodeans>=ans[0])return nodeans;
    else return max(nodeans,ans[1]);
}




 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;


    cin>>n>>T;
    forr(i,1,n)cin>>x[i];
    forr(i,1,n)cin>>t[i];
    int p,l;
    forr(i,2,n)
    {
        cin>>p>>l;
        adj[p].push_back({i,l});
    }
    cout<<get(1,0)<<endl;


return 0;
}
