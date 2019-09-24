//http://zobayer.blogspot.com/2010/02/primitive-root.html
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
const int N=300007,M=1000000;
const double EPS= 1e-9,eps=-1e9;


int fPower(ll b, ll p, ll m){    //O(log(p))
  ll res = 1;
  while(p){
    if(p&1) res = (res * b)%m;
    b = (b * b)%m;
    p >>= 1;
  }
  return (int)res;
}


int p,r,n;

 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
//input;

while(scanf("%d%d",&p,&n),p||n)
{
    vector<int>v;
    int g=p-1;
    for(int i=2;i*i<=g;i++)
    {
        while(g%i==0)
        {
            v.push_back(i);
            g/=i;
        }
    }
    if(g>1)v.push_back(g);

    forr(i,1,n)
    {
        scanf("%d",&r);
        int ck=1;
        for(auto t:v)
        if(fPower(r,(p-1)/t,p)==1)
        {
            ck=0;
            break;
        }


        if(ck)printf("YES\n");
        else printf("NO\n");
    }
}

return 0;
}
