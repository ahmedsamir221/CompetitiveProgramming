//https://github.com/yazanKabbany/CompetitiveProgramming/blob/master/UVA/UVA%201406.cpp
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
const int N=1<<16,M=1000000;
int n,a[N],ans[16][N],cnt[N*2];
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;
      int cas=0;
      while(cin>>n,n!=-1)
      {
          memset(a,0,sizeof a);
          int x;
          forr(i,1,n)cin>>x,a[x]++;

          memset(ans,0,sizeof ans);
          for(int bit=15;bit>-1;bit--)
          {
              int m=1<<(bit+1);
              memset(cnt,0,sizeof cnt);
              for(int i=0;i<(1<<16);i++)
              {
                  int msk=i&(m-1);
                  cnt[msk]+=a[i];
              }
              for(int i=m;i<2*m;i++)cnt[i]=cnt[i-m];
              for(int i=1;i<2*m;i++)cnt[i]+=cnt[i-1];

              for(int i=2*m-1,j=0;i>=m;i--,j++)
              {
                  int r=i,l=i-m/2;
                  ans[bit][j]=cnt[r] - cnt[l];
              }
          }
          int sum=0;
          ll total=0;
          char ch;
          while(1)
          {
              cin>>ch;
              if(ch=='E')break;
              cin>>x;
              if(ch=='C')sum=(sum+x%(1<<16))%(1<<16);
              else{
                int m=1<<(x+1);
                total+=ans[x][sum%m];
              }
          }
          cout<<"Case "<<++cas<<": "<<total<<endl;

      }

return 0;
}
