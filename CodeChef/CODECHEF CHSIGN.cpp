/*
   we will use dp , our state will be the current number and the state of the previous two numbers .
   state ---> if we changed them or no .
   we need only to check if we can change the current number with the the previous two numbers and
   the next number .
   if it hold the all condition then all contiguous subsequence will also hold .
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
const int N =100005;

int n,a[N];
ll mem[N][2][2];
bool can(int p1,int p2,int i)
{
    if(i+1<=n)
    {
        if(-a[i]+a[i+1]<=0)return 0;
    }
    if(i-1>0)
    {
        if(p1)return 0;
        else {
           if(-a[i]+a[i-1]<=0)return 0;
        }
    }
    if(i-2>0)
    {
        if(p2){
            if(-a[i]-a[i-2]+a[i-1]<=0)return 0;
        }
    }
    return 1;
}
ll dp(int i=1,int p1=0,int p2=0)
{
    if(i>n)return 0;
    ll&ret=mem[i][p1][p2];
    if(~ret)return ret;
    ll c1=dp(i+1,0,p1)+a[i];
    ll c2=1e17;
    if(can(p1,p2,i))c2=dp(i+1,1,p1)-a[i];
    return ret=min(c1,c2);
}

void get(int i=1,int p1=0,int p2=0)
{
    if(i>n)return ;
    ll c1=dp(i+1,0,p1)+a[i];
    ll c2=1e17;
    if(can(p1,p2,i))c2=dp(i+1,1,p1)-a[i];
    if(dp(i,p1,p2)==c1)
    {
        if(i==n)cout<<a[i]<<endl;
        else cout<<a[i]<<" ";
        get(i+1,0,p1);
    }
    else{
        if(i==n)cout<<-a[i]<<endl;
        else cout<<-a[i]<<" ";
        get(i+1,1,p1);
    }
}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;

    int t;
    cin>>t;
    while(t--){
      cin>>n;
      forr(i,1,n)cin>>a[i];
      memset(mem,-1,(n+3)*sizeof mem[0]);
      dp();
      get();
    }



return 0;
}
