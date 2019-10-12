//https://codeforces.com/blog/entry/44538
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
const int N=500009,M=1000000;
const double EPS= 1e-9,eps=-1e9;

int n,ans[N],tree[N];
map<int,vector<pair<pair<int,int>,int>>>m;

void  up(int idx,int v,int mx)
{
    for(;idx<=mx;idx+=idx&-idx)tree[idx]+=v;
}
int get(int idx)
{
    int ans=0;
    for(;idx;idx-=idx&-idx)ans+=tree[idx];
    return ans;
}
void solve(int x)
{
    map<int,int>id;
    vector<int>v;
    int c=0;
    for(auto p:m[x])v.push_back(p.F.S);
    sort(v.begin(),v.end());
    for(auto p:v)id[p]=++c;
    memset(tree,0,(c+3)*sizeof tree[0]);
    for(auto p:m[x])
    {
        int t=id[p.F.S];
        if(p.F.F==1)up(t,1,c);
        else if(p.F.F==2)up(t,-1,c);
        else ans[p.S]=get(t);
    }
}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;

      cin>>n;
      int type,t,v;
      forr(i,1,n)
      {
          cin>>type>>t>>v;
          m[v].push_back({{type,t},i});
      }
      memset(ans,-1,sizeof ans);
      for(auto p:m)solve(p.F);
      forr(i,1,n)
      if(ans[i]!=-1)cout<<ans[i]<<endl;




return 0;
}
