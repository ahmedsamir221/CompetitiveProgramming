/*
   we will add all vector in just one vector and then brute force in all boxes and maximize the answer
*/
#include <iostream>
#include<vector>
#include<algorithm>
//#include <cmath>
//#include <complex>
#include<queue>
#include<map>
#include <string>
#include<bits/stdc++.h>
//#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);
//#define x real()
//#define y imag()
using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
//typedef complex<double> point;
//template<typename T>T gcd(T x, T y) { if(y == 0)return x; else return gcd(y, x%y); }
//typedef bitset<30> mask;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
int q,w,n,m,k,h,t,x,y,b[502];
ll sum[102][102];
int a[102][102];
int main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
//input;
scanf("%d",&w);
while(w--)
{
    scanf("%d%d%d%d%d",&n,&m,&h,&k,&t);
    forr(i,1,n)
    forr(j,1,m)
    scanf("%d",&a[i][j]);

    memset(b,0,sizeof b);
    forr(i,1,t)
    {
        scanf("%d",&x);
        forr(j,1,k)
        {
          scanf("%d",&y);
          b[j]+=x*y;
        }
    }

    ll ans=-2e18;

    forr(i,1,n)
    forr(j,1,m)
    {
          memset(sum,0,sizeof sum);
          forr(u,i,n)
          {
              ll g=0;
              forr(v,j,m)
              {
                 g+=(ll)b[a[u][v]];
                 sum[u][v]+=sum[u-1][v]+g;
                 ans=max(ans,(ll)h+sum[u][v]);
              }
          }
    }
    printf("Case #%d:\n",++q);
    printf("%lld\n",ans);
}
return 0;
}
