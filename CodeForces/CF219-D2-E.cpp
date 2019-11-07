//https://codeforces.com/blog/entry/5160
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
const int N=1000009,M=1000000;
int n,m,id[N];
set<int>s;

struct lex_compare {
    bool operator() (const pair<int,pair<int,int>>& x, const pair<int,pair<int,int>>& y) const {
        if(x.F>y.F)return 1;
        else if(x.F==y.F)
        {
            if(x.S.F<y.S.F)return 1;
            return 0;
        }
        else return 0;
    }
};
set<pair<int,pair<int,int>>,lex_compare>q;
int add(int x)
{
    int res;
    if(s.size()==2)
    {
        res=1;
        s.insert(1);
        q.insert({0,{0,1}});
        q.insert({n-1,{1,n+1}});
    }
    else
    {
        auto it=q.begin();
        auto p=*it;
        q.erase(it);
        int idx;
        if(p.S.F==0)idx=1;
        else if(p.S.S==n+1)idx=n;
        else idx=(p.S.F+p.S.S)/2;
        res=idx;
        auto itt=s.lower_bound(idx);
        int r=*itt;
        itt--;
        int l=*itt;
        s.insert(idx);
        if(l==0)q.insert({idx-1,{0,idx}});
        else q.insert({(idx-l)/2,{l,idx}});

        if(r==n+1)q.insert({n-idx,{idx,r}});
        else q.insert({(r-idx)/2,{idx,r}});
    }
    return res;
}

void remov(int x)
{
    auto it=s.lower_bound(x);
    it++;
    int r=*it;
    it--,it--;
    int l=*it;
    it++;
    s.erase(it);
    if(l==0)q.erase({x-1,{0,x}});
    else q.erase({(x-l)/2,{l,x}});

    if(r==n+1)q.erase({n-x,{x,n+1}});
    else q.erase({(r-x)/2,{x,r}});

    if(l==0&&r==n+1)return;
    else if(l==0)q.insert({r-1,{0,r}});
    else if(r==n+1) q.insert({n-l,{l,n+1}});
    else q.insert({(r-l)/2,{l,r}});
}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;

      cin>>n>>m;
      s.insert(0);
      s.insert(n+1);
      int t,x;
      forr(i,1,m)
      {
          cin>>t>>x;
          if(t==1)id[x]=add(x),cout<<id[x]<<endl;
          else remov(id[x]);
      }

return 0;
}
