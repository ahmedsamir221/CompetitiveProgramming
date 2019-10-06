//https://codeforces.com/blog/entry/19212
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
const int N=100007,M=1000000;
const double EPS= 1e-9,eps=-1e9;


int n,q,val[26][N*18],laz[26][N*18];
string s;
void lazy(int p,int s,int e,int id)
{
    int mid=(s+e)/2;
    val[id][p*2]=(mid-s+1)*laz[id][p];
    laz[id][p*2]=laz[id][p];
    val[id][p*2+1]=(e-mid)*laz[id][p];
    laz[id][p*2+1]=laz[id][p];
    laz[id][p]=-1;
}
int up(int s,int e,int p,int l,int r,int id, int v)
{
    if(l>r)return 0;
    if(s>=l&&e<=r)
    {
        val[id][p]=v*(e-s+1);
        laz[id][p]=v;
        return val[id][p];
    }
    if(laz[id][p]!=-1)lazy(p,s,e,id);
    int mid=(s+e)/2;
    if(r<=mid)return val[id][p]=up(s,mid,p*2,l,r,id,v)+val[id][p*2+1];
    else if(l>mid) return val[id][p]=val[id][p*2]+up(mid+1,e,p*2+1,l,r,id,v);
    else return val[id][p]=up(s,mid,p*2,l,r,id,v)+ up(mid+1,e,p*2+1,l,r,id,v);
}
int get(int s,int e,int p,int l,int r,int id)
{
    if(s>=l&&e<=r)return val[id][p];
    if(laz[id][p]!=-1)lazy(p,s,e,id);
    int mid=(s+e)/2;
    if(r<=mid)get(s,mid,p*2,l,r,id);
    else if(l>mid) return get(mid+1,e,p*2+1,l,r,id);
    else return get(s,mid,p*2,l,r,id)+ get(mid+1,e,p*2+1,l,r,id);
}
 int main()
{
//freopen("reduce.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;


   cin>>n>>q;
   cin>>s;
   memset(laz,-1,sizeof laz);
   for(int i=0;i<n;i++) up(1,n,1,i+1,i+1,s[i]-'a',1);
   int l,r,v;
   while(q--)
   {
       cin>>l>>r>>v;
       if(v==1)
       {
           int init=l;
           for(int i=0;i<26;i++)
           {
              int c=get(1,n,1,init,r,i);
              up(1,n,1,init,r,i,0);
              up(1,n,1,l,l+c-1,i,1);
              l+=c;
           }
       }
       else
       {
           int init=l;
           for(int i=25;i>-1;i--)
           {
              int c=get(1,n,1,init,r,i);
              up(1,n,1,init,r,i,0);
              up(1,n,1,l,l+c-1,i,1);
              l+=c;
           }
       }
   }
   forr(i,1,n)
   {
       for(int j=0;j<26;j++)
       {
           if(get(1,n,1,i,i,j))
           {
               cout<<(char)(j+'a');
               break;
           }
       }
   }




return 0;
}
