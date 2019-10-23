/*
   we need to try to end in all position and maximize the answer .
   if we do not stop we will reach position i  after i second , so if (t[i] > i) then we need to wait
   (t[i] - i)  second to eat the food in it .
   so if I will end at position i , I will have (t - i - 1) additional second and I will wait them at position 0 .
   if we can answer the query of number of position from 1 to i that need to wait  (t - i - 1) second or less
   then I can get the answer , we can do that by segment tree .
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
const int N =300005;

int n,t,a[N];
vector<int>val[N*20];

void bulid(int s=1,int e=n,int p=1)
{
    if(s==e)
    {
        val[p].push_back(a[s]);
        return;
    }
    int mid=(s+e)/2;
    bulid(s,mid,p*2);
    bulid(mid+1,e,p*2+1);
    val[p].resize(e-s+1);
    merge(val[p*2].begin(),val[p*2].end(),val[p*2+1].begin(),val[p*2+1].end(),val[p].begin());
}

int get(int s,int e,int p,int l,int r,int v)
{
    if(s>=l&&e<=r)
    {
        auto it=upper_bound(val[p].begin(),val[p].end(),v);
        return it-val[p].begin();
    }
    int mid=(s+e)/2;
    if(r<=mid)return get(s,mid,p*2,l,r,v);
    else if(l>mid)return get(mid+1,e,p*2+1,l,r,v);
    else return get(s,mid,p*2,l,r,v)+get(mid+1,e,p*2+1,l,r,v);
}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;


     cin>>n>>t;
     forr(i,1,n)cin>>a[i],a[i]-=i;
     bulid();
     int ans=0;
     forr(i,1,n)
     {
         if(i>=t)break;
         int g=get(1,n,1,1,i,t-i-1);
         ans=max(ans,g);
     }
     cout<<ans;

return 0;
}
