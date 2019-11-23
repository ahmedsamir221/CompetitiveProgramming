//https://codeforces.com/blog/entry/61876
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
const int N = 1006 + 3, M = 5e4 + 3;
int n,cnt[N],k[N],tak[N];
vector<int>a[N];

 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
//input;
     scanf("%d",&n);
     memset(cnt,-1,sizeof cnt);
     int u,v,ck=1;
     forr(i,1,n-1)
     {
         scanf("%d %d",&u,&v);
         if(u>v)swap(u,v);
         if(v!=n)ck=0;
         cnt[u]++;
         tak[u]=1;
     }
     if(!ck)
     {
         cout<<"NO";
         return 0;
     }
     forr(i,1,n-1)
         if(cnt[i]==-1)k[i]=1;

     for(int i=n-1;i>0;i--)
     {
         for(int j=i-1;j>0;j--)
         {
             if(k[j]&&cnt[i]>0)
             {
                 k[j]=0;
                 a[i].push_back(j);
                 cnt[i]--;
             }
         }
     }

     forr(i,1,n)
     {
         if(k[i])
         {
             cout<<"NO";
             return 0;
         }
     }
     vector<pair<int,int>>ans;
     forr(i,1,n-1)
     {
         if(tak[i]==0)continue;
         a[i].push_back(i);
         ans.push_back({n,a[i][0]});
         for(int j=1;j<(int)a[i].size();j++)ans.push_back({a[i][j-1],a[i][j]});
     }
     cout<<"YES"<<endl;
     for(auto p:ans)cout<<p.F<<" "<<p.S<<endl;




return 0;
}
