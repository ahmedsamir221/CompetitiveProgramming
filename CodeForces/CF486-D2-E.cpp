/*
    we will calculate the LIS that end at position i and call it l[i] and the LIS that begin at position i
    and call it r[i] .
    if(l[i]+r[i]-1 != LIS of the original sequence) it belong to group 1 .
    else {
       will check all l[i] if any value repeated then all position that have this value belong to group 2 .
       the position with unique values belong to group 3 .
    }
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
const int N=100009,M=1000000;
const double EPS= 1e-9,eps=-1e9;

int n,a[N],l[N],r[N],val[N*20],ans[N];

int up(int s,int e,int p,int idx,int v)
{
    //cout<<s<<" "<<e<<" "<<p<<" "<<idx<<" "<<v<<endl;
    if(s==e) return val[p]=max(val[p],v);
    int mid=(s+e)/2;
    if(idx<=mid) return val[p]=max(up(s,mid,p*2,idx,v),val[p*2+1]);
    else return val[p]=max(val[p*2],up(mid+1,e,p*2+1,idx,v));
}
int get(int s,int e,int p,int l,int r)
{
    if(l>r)return 0;
    if(s>=l&&e<=r)return val[p];
    int mid=(s+e)/2;
    if(r<=mid)return get(s,mid,p*2,l,r);
    else if(l>mid) return get(mid+1,e,p*2+1,l,r);
    else return max(get(s,mid,p*2,l,r),get(mid+1,e,p*2+1,l,r));
}

 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;


    cin>>n;
    forr(i,1,n)cin>>a[i];
    int mx=0;
    forr(i,1,n)
    {
      int g=get(1,100000,1,1,a[i]-1);
      l[i]=g+1;
      //cout<<g<<endl;
      mx=max(mx,l[i]);
      up(1,100000,1,a[i],l[i]);
    }
    memset(val,0,sizeof val);
    for(int i=n;i>=1;i--)
    {
      int g=get(1,100000,1,a[i]+1,100000);
      r[i]=g+1;
      up(1,100000,1,a[i],r[i]);
    }
   // cout<<mx<<endl;
    map<int,int>m;
    forr(i,1,n)
    {
         if(l[i]+r[i]-1!=mx)ans[i]=1;
         else m[l[i]]++;
    }
    forr(i,1,n)
    {
         if(ans[i]==1)continue;

         if(m[l[i]]==1)ans[i]=3;
         else ans[i]=2;
    }
    forr(i,1,n)cout<<ans[i];




return 0;
}
