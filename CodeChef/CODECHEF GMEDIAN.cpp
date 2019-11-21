/*
   we will take each element and find the all subsequences that it is the median of it .
   so if that number is x  , l = the number of element < x  and r = the number of element > x
   so the number of subsequences will (l+r)C(l)
   that was if the size of subsequences is odd .
   we can get even subsequences if the two element of median are equal , so we will check  every two
   equal number and do the previous thing .

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
const int N = 1006 + 3, M = 5e4 + 3;
int n,a[N];
int mod = 1000000007;
int MAXN = 2010;
long comb[2020][2020] ;

void pre()
{
    comb[0][0] = 1;
    for (int i = 1; i < MAXN; i++) {
    comb[i][0] = 1;
    for (int j = 1; j <= i; j++) {
        comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % mod;
      }
    }
}

 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
//input;
    pre();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        sort(a,a+n);
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            int l=i;
            int r=n-i-1;
            ans+=comb[l+r][l];
            ans%=mod;
        }
        for(int i=0;i<n;i++)
        {
          for(int j=i+1;j<n;j++)
          {
            if(a[i]!=a[j])continue;
            int l=i;
            int r=n-j-1;
            ans+=comb[l+r][l];
            ans%=mod;
          }
        }
        printf("%lld\n",ans);
    }




return 0;
}
