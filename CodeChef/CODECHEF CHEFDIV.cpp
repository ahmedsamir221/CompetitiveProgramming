//https://discuss.codechef.com/t/chefdiv-editorial/14413
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
const int N =3000005;
ll l,r,ans,p[N];
map<ll,vector<ll>>ck;
ll fact(ll a,ll b)
{
    for(ll i=2;i<=1e6;i++)
        if(p[i]==0)
        for(ll j=i;j<=1e6;j+=i)p[j]=i;

    for(ll i=2;i<=1e6;i++)
    {
        ll st=a;
        if(a%i){
          st=i-a%i;
          st+=a;
        }
        if(p[i]!=i)continue;
        for(ll j=st;j<=b;j+=i)ck[j].push_back(i);
    }

    for(ll i=a;i<=b;i++)
    {
       priority_queue<ll>q;
       ll x=i,d=1;
       for(auto t:ck[i])
       {
           ll c=0;
           while(x%t==0)
           {
               c++;
               x/=t;
           }
           d*=(c+1);
           q.push(c+1);
       }
       if(x>1)
       {
           d*=2;
           q.push(2);
       }
       while(q.size())
       {
           ans+=d;
           ll g=q.top();
           d=d/g*(g-1);
           q.pop();
           if(g-1)q.push(g-1);
       }
    }
}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
//input;

     scanf("%lld %lld",&l,&r);
     fact(l,r);
     cout<<ans-(r-l+1)+(l==1?1:0)<<endl;


return 0;
}
