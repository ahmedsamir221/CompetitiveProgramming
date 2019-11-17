//https://codeforces.com/blog/entry/45310
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
//const int N=5009*2,M=30000000;

const int N = 5e4 + 3, M = 5e4 + 3;
ll n,x,cur=1,k[100009];
vector<ll>v;
pii get(ll cur ,ll sum , ll cnt )
{
    if(cur<=0)return {cnt,n-sum};
    auto a=upper_bound(v.begin(),v.end(),cur);
    a--;
    auto b=a;
    if(*b!=1)b--;
    ll A=a-v.begin()+1;
    ll B=b-v.begin()+1;
    return max(get(cur-k[A],sum,cnt+1),get((k[A]-1)-k[B],sum+cur-(k[A]-1),cnt+1));
}

 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;
       forr(i,1,100005)k[i]=1LL*i*i*i,v.push_back(k[i]);
       cin>>n;
       auto ans=get(n,0,0);
       cout<<ans.F<<" "<<ans.S<<endl;


return 0;
}
