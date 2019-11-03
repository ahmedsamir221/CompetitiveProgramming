//https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/SPOJ/SPOJ_FSEQ.cpp
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
const int N =3000005;
ll m,f[N],dp[N],nxt[N];
ll get(ll mod)
{
    f[0]=0,f[1]=1;
    int i=2;
    for(;;i++)
    {
        if(i>2&&f[i-2]==0&&f[i-1]==1)
        {
            i-=2;
            break;
        }
        f[i]=f[i-1]%mod+f[i-2]%mod;
        f[i]%=mod;
    }
    for(int j=i;j<i*2;j++)f[j]=f[j-i];
    stack<ll>k;
    for(int j=0;j<i*2;j++)
    {
        int x=f[j];
        while(k.size()&&x>f[k.top()])
        {
            nxt[k.top()]=j;
            k.pop();
        }
        k.push(j);
    }
    while(k.size())
    {
        nxt[k.top()]=1e6+7;
        k.pop();
    }
    ll res=0;
    for(int j=2*i-1;j>-1;j--)
    {
        dp[j]=dp[nxt[j]]+1;
        if(j<i)res+=dp[j];
    }
    return res;

}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
//input;
     int t,cas=0;
     scanf("%d",&t);
     while(t--)
     {
         scanf("%lld",&m);
         if(m==1)printf("Case %d: 1\n",++cas);
         else
         {
             ll ans=get(m);
             printf("Case %d: %lld\n",++cas,ans);
         }
     }


return 0;
}
