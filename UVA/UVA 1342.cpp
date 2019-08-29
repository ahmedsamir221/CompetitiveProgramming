//https://github.com/morris821028/UVa/blob/master/volume013/1342%20-%20That%20Nice%20Euler%20Circuit.cpp
#include<bits/stdc++.h>
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
const int N=100006,M=1000000;
const double eps= 1e-9,EPS= 1e-9;

int n,x[400],y[400];


double dot(point a, point b) {
	return a.X * b.X + a.Y * b.Y;
}
double cross(point o, point a, point b) {
    return (a.X-o.X)*(b.Y-o.Y)-(a.Y-o.Y)*(b.X-o.X);
}

int between(point a, point b, point c) {
	return dot(c - a, b - a) >= -eps && dot(c - b, a - b) >= -eps;
}
int onSeg(point a, point b, point c) {
	return between(a, b, c) && fabs(cross(a, b, c)) < eps;
}
bool intersectSegments(point a, point b, point c, point d, point & intersect) {
  double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
  if (fabs(d1) < EPS)
    return false;  // Parllel || identical

  double t1 = d2 / d1, t2 = d3 / d1;
  intersect = a + (b - a) * t1;

  if (t1 < -EPS || t1 > 1+EPS || t2 < -EPS || t2 > 1+EPS)
    return false;  //e.g ab is ray, cd is segment ... change to whatever
  return true;
}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
//input;
int cas=0;
while(cin>>n,n)
{
   set<pair<double,double>>s;
   forr(i,0,n-1)cin>>x[i]>>y[i],s.insert({x[i],y[i]});
   int e=n-1,v;
   point k(0,0);
   forr(i,3,n-1)
   {
       point A(x[i-1],y[i-1]);
       point B(x[i],y[i]);
       forr(j,1,i-2)
       {
           point C(x[j-1],y[j-1]);
           point D(x[j],y[j]);
           if(intersectSegments(A,B,C,D,k))
           {
               s.insert({k.X,k.Y});
           }

       }
   }
   for(auto p:s)
   {
       forr(i,1,n-1)
       {
             point A(x[i-1],y[i-1]);
             point B(x[i],y[i]);
             point C(p.F,p.S);
             if(onSeg(A,B,C)&&C!=A&&C!=B)e++;
       }
   }
   v=s.size();
   printf("Case %d: There are %d pieces.\n",++cas,e-v+2);
}
return 0;
}
