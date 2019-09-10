/*
   if we take three adjacent points x , y , z  from the polygon then move point y perpendicular to
   segment ( x , z) distance  d*2 and the angle (xyz) became >= 180 then distance d make the polygon not convex.
   so we can binary search about the answer .

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


#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);

#define x real()
#define y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep ,cos
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel , sin
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

const double PI  = acos(-1.0);
using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
typedef complex<double> point;

//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
const int N=1007,M=1000000;
const double EPS= 1e-9;

int n,a[N],b[N];

double projectLine(point as, point ae, point p) {
	double a, b, c, v;
	a = as.y - ae.y, b = ae.x - as.x;
	c = - (a * as.x + b * as.y);
	v = a * p.x + b * p.y + c;
	point k(p.x - v*a / (a*a+b*b), p.y - v*b/ (a*a+b*b));
	return length(k-p);
}
bool ok(double mid)
{
    for(int i=0;i<n;i++)
    {
        int u=(i-1+n)%n;
        int v=(i+1+n)%n;
        point A(a[u],b[u]);
        point B(a[v],b[v]);
        point C(a[i],b[i]);
        if(projectLine(A,B,C) <= mid*2 + EPS)return 0;
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
forr(i,0,n-1)cin>>a[i]>>b[i];

double l=0,r=1e15,mid;
forr(i,1,1000)
{
    mid=(l+r)/2;
    if(ok(mid))l=mid;
    else r=mid;
}
cout<<fixed<<setprecision(12)<<l<<endl;

return 0;
}
