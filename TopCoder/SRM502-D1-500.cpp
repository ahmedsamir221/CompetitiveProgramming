//https://apps.topcoder.com/wiki/display/tc/SRM+502
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
//const int N =300005;
ll mem[55][100005];
ll n,t;
pair<ll,pii>a[55];

bool com(pair<ll,pii> i,pair<ll,pii> j)
{
    if(j.F*i.S.F>i.F*j.S.F)return 1;
    return 0;
}
ll dp(int i=0,int c=0)
{
  if(c>t)return -1e9;
  if(i==n)return 0;
  ll&ret=mem[i][c];
  if(~ret)return ret;
  ll c1=dp(i+1,c+a[i].F)+(a[i].S.S-(a[i].F+c)*a[i].S.F);
  ll c2=dp(i+1,c);
  return ret=max(c1,c2);

}
class TheProgrammingContestDivOne{
public:
    int find(int T, vector <int> maxPoints, vector <int> pointsPerMinute, vector <int> requiredTime){
        n=maxPoints.size();
        t=T;
        for(int i=0;i<n;i++)
        {
            a[i].F=requiredTime[i];
            a[i].S.F=pointsPerMinute[i];
            a[i].S.S=maxPoints[i];
        }
        sort(a,a+n,com);
        memset(mem,-1,sizeof mem);
        return dp();
    }
};
