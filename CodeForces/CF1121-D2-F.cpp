//https://codeforces.com/blog/entry/65679
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

int n,a,b,mx[N],mem[N];
char str[N], pat[N];
int F[N];
string s;

int getNextLen(int len, char c){
  while(len && pat[len] != c)
    len = F[len-1];
  if(pat[len] == c) ++len;
  return len;
}

void computeF(){
  F[0] = 0;
  for(int i = 1 ; i <= n ; ++i)
    F[i] = getNextLen(F[i-1], pat[i]);
}

int dp(int i=0)
{
    if(i==n)return 0;
    int&ret=mem[i];
    if(~ret)return ret;
    int c1=dp(i+1)+a;
    int c2=1e8;
    if(mx[i])c2=dp(i+mx[i])+b;
    return ret=min(c1,c2);
}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;

      cin>>n>>a>>b;
      cin>>s;
      for(int i=1;i<n;i++)
      {
          int c=0;
          for(int j=i;j<n;j++)pat[c++]=s[j];
          pat[c++]='&';
          for(int j=0;j<i;j++)pat[c++]=s[j];
          computeF();
          int ck=0;
          for(int j=0;j<=n;j++)
          {
              if(ck)mx[i]=max(mx[i],F[j]);
              if(pat[j]=='&')ck=1;
          }
      }

      memset(mem,-1,sizeof mem);
      cout<<dp();







return 0;
}
