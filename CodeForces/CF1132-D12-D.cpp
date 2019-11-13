//https://codeforces.com/blog/entry/65752
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
const int N=200009,M=1000000;
int n,k,b[N];
ll a[N];
bool ok(ll x)
{
    priority_queue<pair<pair<ll,int>,int>,vector<pair<pair<ll,int>,int>>,greater<pair<pair<ll,int>,int>>>q;
    forr(i,1,n)q.push({{a[i]/b[i]+1,a[i]%b[i]},i});
    int cnt=0;
    for(int i=1;i<=k;i++)
    {
        cnt++;
        while(1)
        {
          pair<pair<ll,int>,int> g=q.top();
          ll  s=g.F.F;
          int rm=g.F.S,j=g.S;
          if(s<=i&&i!=k)
          {
              q.pop();
              if(1LL*cnt*x+rm*1LL<1LL*b[j]*(i-s+1))return 0;
              ll g=(1LL*cnt*x+rm*1LL)-(1LL*b[j]*(i-s+1));
              ll d=g/x;
              ll t=(cnt-d)*x+rm;
              cnt=d;
              q.push({{s+t/b[j],t%b[j]},j});
          }
          else break;
        }
    }
    return 1;
}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
//input;
     scanf("%d %d",&n,&k);
     forr(i,1,n)scanf("%lld",&a[i]);
     forr(i,1,n)scanf("%d",&b[i]);
     ll l=0,r=1e13,mid;
     while(l<r)
     {
         mid=(l+r)/2;
         if(ok(mid))r=mid;
         else l=mid+1;
     }
     if(l==1e13)cout<<"-1"<<endl;
     else cout<<l<<endl;




return 0;
}
