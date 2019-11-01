//https://codeforces.com/blog/entry/17119
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
ll n,k,s,a[50],f[20],ans;
map<pii,ll>cnt;
void bk1(int i=1,ll sum=0,ll c=0)
{
    if(i>(n+1)/2)
    {
        cnt[{sum,c}]++;
        return;
    }
    if(a[i]>18){
      bk1(i+1,sum,c);
      bk1(i+1,sum+a[i],c);
    }
    else
    {
        bk1(i+1,sum,c);
        bk1(i+1,sum+a[i],c);
        bk1(i+1,sum+f[a[i]],c+1);
    }
}

void bk2(int i=(n+1)/2+1,ll sum=0,ll c=0)
{
    if(i>n)
    {
        for(int j=0;c+j<=k;j++)
        {
            ans+=cnt[{s-sum,j}];
        }
        return;
    }
    if(a[i]>18){
        bk2(i+1,sum,c);
        bk2(i+1,sum+a[i],c);
    }
    else
    {
        bk2(i+1,sum,c);
        bk2(i+1,sum+a[i],c);
        bk2(i+1,sum+f[a[i]],c+1);
    }
}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;
    f[1]=1;
    forr(i,2,18)f[i]=f[i-1]*(ll)i;

    cin>>n>>k>>s;
    forr(i,1,n)cin>>a[i];
    bk1();
    bk2();
    cout<<ans;


return 0;
}
