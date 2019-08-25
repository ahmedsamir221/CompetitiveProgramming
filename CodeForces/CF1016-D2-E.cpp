//https://codeforces.com/blog/entry/61015
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


#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);


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




using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
typedef complex<double> point;

//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
const int N=200006,M=1000000;
const double EPS= 1e-9;

int n,lo[N],hi[N],a,b,s;
int q,x,y;
ll dif[N];
bool intersectSegments(point a, point b, point c, point d, point & intersect) {
  double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
  if (fabs(d1) < EPS)
    return false;  // Parllel || identical

  double t1 = d2 / d1, t2 = d3 / d1;
  intersect = a + (b - a) * t1;

  if (t2 < -EPS )
    return false;  //e.g ab is ray, cd is segment ... change to whatever
  return true;
}

bool ok(int j)
{
    point A(x,y);
    point B(hi[j],0);
    point C(a,s);
    point D(b,s);
    point K(0,0);
    bool ck=intersectSegments(A,B,C,D,K);
    if(ck)return 1;
    else return 0;

}


bool ok2(int j)
{
    point A(x,y);
    point B(lo[j],0);
    point C(a,s);
    point D(b,s);
    point K(0,0);
    bool ck=intersectSegments(A,B,D,C,K);
    if(ck)return 1;
    else return 0;

}

 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;

cin>>s>>a>>b;
cin>>n;
forr(i,1,n)cin>>lo[i]>>hi[i];

forr(i,2,n)
{
    dif[i]=lo[i]-hi[i-1];
    dif[i]+=dif[i-1];
}
cin>>q;
while(q--)
{
    cin>>x>>y;
    int l=1,r=n,mid;
    while(l<r)
    {
        mid=(l+r)/2;
        if(ok(mid))r=mid;
        else l=mid+1;
    }
    int ls=l;

    l=1,r=n,mid;
    while(l<r)
    {
        mid=(l+r+1)/2;
        if(ok2(mid))l=mid;
        else r=mid-1;
    }
    int rs=l;

    if(ls>rs)cout<<fixed<<setprecision(12)<<0<<endl;
    else{
        point A(x,y);
        point B(lo[ls],0);
        point C(a,s);
        point D(b,s);
        point u(0,0);
        point v(0,0);
        intersectSegments(A,B,C,D,u);
        if(u.X<a)u={a,s};

        B={hi[rs],0};
        intersectSegments(A,B,C,D,v);
        if(v.X>b)v={b,s};
        double ans=max(v.X-u.X,0.0);
        double kf=(y+abs(s))*1.0/y;
        ans-=(dif[rs]-dif[ls])*kf;
    //    cout<<ls<<" "<<rs<<" "<<kf<<endl;
     cout<<fixed<<setprecision(12)<<ans<<endl;
    }
}

return 0;
}
