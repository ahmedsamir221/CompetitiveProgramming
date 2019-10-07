//https://pastebin.com/7gEHXy7Z
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
const int N=2000009,M=1000000;
const double EPS= 1e-9,eps=-1e9;
int mx=2000004;
int luck[N],val[N*22], a[N];
int bulid(int s=1,int e=mx,int p=1)
{
    if(s==e)return val[p]=a[s];
    int mid=(s+e)/2;
    return val[p]=bulid(s,mid,p*2)+bulid(mid+1,e,p*2+1);
}

int get(int s,int e,int p,int k)
{
    if(s==e)return s;
    int mid=(s+e)/2;
    if(val[p*2]<k)return get(mid+1,e,p*2+1,k-val[p*2]);
    else return get(s,mid,p*2,k);
}

int up(int s,int e,int p,int k)
{
    if(s==e)return val[p]=0;
    int mid=(s+e)/2;
    if(val[p*2]<k)return val[p]=val[p*2]+up(mid+1,e,p*2+1,k-val[p*2]);
    else return val[p]=up(s,mid,p*2,k)+val[p*2+1];
}

 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
//input;


   for(int i=1;i<=mx;i+=2)a[i]=1;
   bulid();
   luck[1]=1;
   for(int i=2;i<=mx;i++)
   {
       int idx=get(1,mx,1,i);
       luck[idx]=1;
       int cnt=0;
       for(int j=idx;j-cnt<=mx;j+=idx)up(1,mx,1,j-cnt),cnt++;
   }
   int n;
   while(scanf("%d",&n)==1){
     if(n%2)
     {
         printf("%d is not the sum of two luckies!\n",n);
         continue;
     }
     int ck=0;
     for(int i=n/2;i>=1;i--)
     {
         if(luck[i]&&luck[n-i])
         {
             printf("%d is the sum of %d and %d.\n",n,i,n-i);
             ck=1;
             break;
         }
     }
     if(!ck)printf("11 is not the sum of two luckies!\n",n);
   }





return 0;
}
