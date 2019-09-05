//https://codeforces.com/blog/entry/8755
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
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
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
const int N=100007,M=1000000;
const double EPS= 1e-9;

int n,a[N],b[N];


double get(vector<point> &p) {
    double area = 0;
    int n = p.size();
    for(int i = 0; i < n;i++)
		area += p[i].x * p[(i+1)%n].y - p[i].y * p[(i+1)%n].x;
    return fabs(area) /2;
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

 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;
cin>>n;
forr(i,1,n)
{
    cin>>a[i]>>b[i];
}

double ans=0;
forr(i,1,n)
{
    forr(j,i+1,n)
    {
        point A(a[i],b[i]);
        point B(a[j],b[j]);
        vector<point>v;
        v.push_back(A);
        v.push_back(B);
        double dis1=0,dis2=0;
        forr(k,1,n)
        {
            if(k==i||k==j)continue;
            point C(a[k],b[k]);
            v.push_back(C);
            if(ccw(A,B,C)==1)dis1=max(dis1,get(v));
            else dis2=max(dis2,get(v));
            v.pop_back();
        }
        if(dis1>EPS&&dis2>EPS)
        ans=max(ans,dis1+dis2);
    }
}
cout<<fixed<<setprecision(9)<<ans<<endl;
return 0;
}
