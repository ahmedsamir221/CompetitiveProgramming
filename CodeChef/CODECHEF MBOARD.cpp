//https://github.com/tanmoy13/CompetitveProgramming/blob/master/Online-Judge-Solutions/CodeChef/CODECHEF%20MBOARD.cpp
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
int const mx=1e7+3;
int tree[2][2][5*100000+5],last[2][N],val[2][N];
int n,q;
void up(int type,int val,int idx,int t)
{
    if(idx==0)return;
    for(;idx<=q;idx+=idx&-idx)tree[type][val][idx]+=t;
}

int query(int type,int val,int idx)
{
    int ans=0;
    for(;idx;idx-=idx&-idx)ans+=tree[type][val][idx];
    return ans;
}
char k[50];
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
//input;

   scanf("%d%d",&n,&q);
   int idx,r,c,v;
   forr(i,1,q)
   {
       scanf(" %s",k);
       string s=(k);
       if(s=="RowQuery")
       {
           scanf("%d",&idx);
           if(val[0][idx]==1)printf("%d\n",query(1,0,i)-query(1,0,last[0][idx]));
           else printf("%d\n",n-query(1,1,i)+query(1,1,last[0][idx]));
       }
       else if(s=="ColQuery")
       {
           scanf("%d",&idx);
           if(val[1][idx]==1)printf("%d\n",query(0,0,i)-query(0,0,last[1][idx]));
           else printf("%d\n",n-query(0,1,i)+query(0,1,last[1][idx]));
       }
       else if(s=="RowSet")
       {
           scanf("%d%d",&idx,&v);
           up(0,val[0][idx],last[0][idx],-1);
           up(0,v,i,1);
           last[0][idx]=i;
           val[0][idx]=v;
       }
       else
       {
           scanf("%d%d",&idx,&v);
           up(1,val[1][idx],last[1][idx],-1);
           up(1,v,i,1);
           last[1][idx]=i;
           val[1][idx]=v;
       }
   }


return 0;
}
