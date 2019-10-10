//https://github.com/magdy-hasan/competitive-programming/blob/99949526fddbb0857a233c02342293b21e5f242d/SPOJ/SPOJ%20CCOST%20-%20Calculate%20The%20Cost.cpp
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
int tree[mx];
int ans[600000];
struct level{
   int x,ys,ye,id,type,mul,val;
};
level arr[mx+3];

bool com(level a,level b)
{
    if(a.x<b.x)return 1;
    else if(a.x==b.x&&a.type<b.type)return 1;
    else return 0;
}
void up(int idx,int v)
{
   for(;idx<=mx;idx+=idx&-idx)tree[idx]+=v;
}

int query(int idx)
{
    int ans=0;
    for(;idx;idx-=idx&-idx)ans+=tree[idx];
    return ans;
}

 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;

   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       int x,y,v,c=0;
       forr(i,1,n)
       {
           cin>>x>>y>>v;
           x++,y++;
           arr[c].x=x;
           arr[c].ys=y;
           arr[c].type=1;
           arr[c].val=v;
           c++;
       }
       int q,r1,c1,r2,c2;
       cin>>q;
       forr(i,0,q-1)
       {
           cin>>r1>>c1>>r2>>c2;
           r1++,c1++,r2++,c2++;
           arr[c].x=r1;
           arr[c].ys=c1;
           arr[c].ye=c2;
           arr[c].type=0;
           arr[c].id=i;
           arr[c].mul=-1;
           c++;
           arr[c].x=r2;
           arr[c].ys=c1;
           arr[c].ye=c2;
           arr[c].type=2;
           arr[c].id=i;
           arr[c].mul=1;
           c++;

       }
       sort(arr,arr+c,com);
       memset(ans,0,q*sizeof ans[0]);
       memset(tree,0,sizeof tree);
       for(int i=0;i<c;i++)
       {
           //cout<<arr[i].type<<endl;
           if(arr[i].type!=1)
           {
               ans[arr[i].id]+=arr[i].mul*(query(arr[i].ye)-query(arr[i].ys-1));
           }
           else
           {
               up(arr[i].ys,arr[i].val);
           }
       }
       for(int i=0;i<q;i++)cout<<ans[i]<<endl;

   }







return 0;
}
