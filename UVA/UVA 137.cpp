/*
   we need to get the area of intersect between the two polygons , we can do that by get the points of intersect
   between the sides of the two polygons and the points inside each other and sort them in clock wise order
   then get the area of that new polygon .
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

int n,m;

double dot(point a, point b) {
	return a.x * b.x + a.y * b.y;
}
double cross(point o, point a, point b) {
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}
double cross2(point a, point b) {
    return a.x * b.y - a.y * b.x;
}
int between(point a, point b, point c) {
	return dot(c - a, b - a) >= -eps && dot(c - b, a - b) >= -eps;
}
int onSeg(point a, point b, point c) {
	return between(a, b, c) && fabs(cross(a, b, c)) < eps;
}

double polygonArea(vector<point> &p) {
    double area = 0;
    int n = p.size();
    for(int i = 0; i < n;i++)
		area += p[i].x * p[(i+1)%n].y - p[i].y * p[(i+1)%n].x;
    return fabs(area) /2;
}

int inPolygon(vector<point> &p, point q) {
	int i, j, cnt = 0;
	int n = p.size();
	for(i = 0, j = n-1; i < n; j = i++) {
		if(onSeg(p[i], p[j], q))
			return 1;
		if(p[i].y > q.y != p[j].y > q.y &&
		q.x < (p[j].x-p[i].x)*(q.y-p[i].y)/(p[j].y-p[i].y) + p[i].x)
		cnt++;
	}
	return cnt&1;
}

bool intersectSegments(point a, point b, point c, point d, point & intersect) {
  double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
  if (fabs(d1) < EPS)
    return false;  // Parllel || identical

  double t1 = d2 / d1, t2 = d3 / d1;
  intersect = a + (b - a) * t1;

  if (t1 < -EPS ||t1 > 1+EPS || t2 < -EPS || t2 > 1 + EPS)
    return false;  //e.g ab is ray, cd is segment ... change to whatever
  return true;
}
int ccw(point a, point b, point c) {
  point v1(b - a), v2(c - a);
  double t = cp(v1, v2);

  if (t > +EPS)
	return +1;
  if (t < -EPS)
	return -1;
  if (v1.x * v2.x < -EPS || v1.y * v2.y < -EPS)
	return -1;
  if (norm(v1) < norm(v2) - EPS)
	return +1;
  return 0;
}
int com(point a,point b)
{
    if(fabs(a.x -b.x) <= EPS && fabs(a.y - b.y) <= EPS  )return 0;
    else if(a.x > b.x +EPS) return 1;
    else if(fabs(a.x - b.x) <= EPS && a.y > b.y + EPS)return 1;
    else return -1;
}

double get(vector<point> &a,vector<point> &b)
{
    vector<point>k;
    for(int i=0;i<n;i++)
    {
        if(inPolygon(b,a[i]))k.push_back(a[i]);
        for(int j=0;j<m;j++)
        {
             point t(0,0);
             if(intersectSegments(a[i],a[(i+1)%n],b[j],b[(j+1)%m],t))k.push_back(t);
        }

    }
    for(int i=0;i<m;i++)
        if(inPolygon(a,b[i]))k.push_back(b[i]);
    vector<point>v,t;
    for(int i=0;i<k.size();i++)
    {
        int ck=1;
        for(auto p:v)if(com(k[i],p)==0)ck=0;
        if(ck)v.push_back(k[i]);
    }
    int g=v.size()-1;

    while(v.size()&&g--)
    {
      point c(0,0);
      if(t.size()==0)c=v[0],t.push_back(v[0]);
      else c=t[t.size()-1];

      for(auto i:v)
      {
          if(com(i,c)==0)continue;
          int ck=1;
          for(auto j:v)
          {
              if(com(j,i)==0||com(j,c)==0)continue;
              if(ccw(c,i,j)!=1)ck=0;
          }
          if(ck)
          {
              t.push_back(i);
              break;
          }
      }

    }

    return polygonArea(t);

}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;

while(cin>>n,n)
{
    vector<point>a,b;
    int u,v;
    forr(i,1,n)
    {
       cin>>u>>v;
       a.push_back({u,v});
    }
    cin>>m;
    forr(i,1,m)
    {
       cin>>u>>v;
       b.push_back({u,v});
    }
    double area=polygonArea(a)+polygonArea(b)-2*get(a,b);
    cout<<setw(8)<<fixed<<setprecision(2)<<area;
}
cout<<endl;


return 0;
}
