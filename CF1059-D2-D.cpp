//https://codeforces.com/blog/entry/62238
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


#define X real()
#define Y imag()
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
typedef complex<long double> point;

//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
const int N=500007,M=1000000;
const double EPS= 1e-9;

int n,m,k;
point a[N];


bool ok(long double y)
{
   long double mn=-1e18,mx=1e18;
   forr(i,1,n)
   {
       long double pr=fabs(y-a[i].Y);
       if(pr + EPS > y)return 0;
       long double u= a[i].X - sqrt(y*y -  pr*pr);
       long double v= a[i].X + sqrt(y*y -  pr*pr);
       mn=max(mn,u);
       mx=min(mx,v);
       if(mn > mx)return 0;
   }
   return 1;
}

 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;

cin>>n;
int u,v,ck1=0,ck2=0;
forr(i,1,n)
{
    cin>>u>>v;
    if(v>0)ck1=1;
    if(v<0)ck2=1;
    a[i]={u,abs(v)};
}
if(ck1+ck2==2)
{
    cout<<"-1";
    return 0;
}
long double l=0,r=1e16,mid;
forr(i,1,100)
{
    mid=(l+r)/2;
    if(ok(mid))r=mid;
    else l=mid;
}
cout<<fixed<<setprecision(6)<<l<<endl;



return 0;
}
