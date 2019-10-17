//https://codeforces.com/blog/entry/15148
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
//const int N=500009,M=1000000;
const double EPS= 1e-9,eps=-1e9;
const int N =5000005;
int n;
vector<int>v;
string s,t;
char str[N], pat[N];
int F[N];
 
int getNextLen(int len, char c){
  while(len && pat[len] != c)
    len = F[len-1];
  if(pat[len] == c) ++len;
  return len;
}
 
void computeF(){
  F[0] = 0;
  for(int i = 1 ; i < n ; ++i)
    F[i] = getNextLen(F[i-1], pat[i]);
}
ll mod=1e9+7,mem[200007][2][2],m;
ll dp(int i,int tk,int can)
{
    //cout<<i<<" "<<tk<<" "<<can<<endl;
    if(i>=n)
    {
        if(tk&!can)return 1;
        return 0;
    }
    ll&ret=mem[i][tk][can];
    if(~ret)return ret;
    ret=0;
    if(can)
    {
        ret+=dp(i+1,max(tk,1),0)%mod;
        ret+=dp(i+1,tk,1)%mod;
    }
    else
    {
        auto it=lower_bound(v.begin(),v.end(),i+m-1);
        if(it!=v.end())ret+=dp(*it,tk,1)%mod;
        if(tk)ret+=dp(i+1,tk,0)%mod;
        //ret+=dp(i+1,0);
    }
    ret%=mod;
    return ret;
}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;
 
    cin>>s>>t;
    for(int i=0;i<t.size();i++)pat[i]=t[i];
    pat[(int)t.size()]='&';
    for(int i=0,j=t.size()+1;i<s.size();i++,j++)pat[j]=s[i];
    n=t.size()+s.size()+1;
    computeF();
    m=t.size();
    for(int i=m+1;i<n;i++)if(F[i]==m)v.push_back(i);
    memset(mem,-1,sizeof mem);
    ll ans=0;
    for(int i=m+1;i<n;i++)ans+=dp(i,0,0)%mod,ans%=mod;
    cout<<ans<<endl;
 
return 0;
}
