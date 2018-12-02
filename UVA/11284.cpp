/*
first get all paths using floyed then try all possible permutation of houses you will visit by dp with mask
convert to integer to avoid WA  because perstion of double
*/



#include<stdio.h>
#include<vector>
#include<algorithm>
#include <iostream>
#include <cmath>
#include <complex>
#include<queue>
#include <string>
#include<bits/stdc++.h>
#define pi 3.141592654
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
typedef bitset<13> mask;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//const double PI = acos(-1.0);
//const double EPS = 1e-9;
//typedef complex<double> point;
ll t,n,m,x,y,b[15],p;
double c;
ll a[55][55],d[15],mem[15][(1<<14)+5];

ll dp(int s,mask m)
 {
     if(m.count()==0)return -a[b[s]][0];
     ll&ret=mem[s][m.to_ulong()];
     if(~ret)return ret;
      ret=-1e18;
      forr(i,1,p)
      {
          if(m[i])
          {
             mask k=m;
             k[i]=0;
             ret=max(dp(i,k)+d[i]-a[b[s]][b[i]],ret);
             ret=max(dp(s,k),ret);
          }
      }
      return ret;
 }

int main()
{

//cout<<Pow((ll)1000000,(ll)110);a
//freopen("tour.in","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
//input;
cin>>t;
while(t--)
{
   cin>>n>>m;
   forr(i,0, n) forr(j,0, n)a[i][j]=1e18;
   forr(i,0,n)a[i][i]=0.0;
   forr(i,1,m)
   {
       cin>>x>>y>>c;
       a[x][y]=min((ll)round(c * 100.0),a[x][y]);
       a[y][x]=a[x][y];
   }

  forr(k,0, n) forr(i,0, n) forr(j,0, n)
   a[i][j] = min(a[i][j], a[i][k]+a[k][j]);

  cin>>p;
  forr(i,1,p)
  {
      cin>>b[i]>>c;
      d[i]=(ll)round(c * 100.0);
  }
  ll ans=0;
  memset(mem,-1,sizeof mem);
  mask g=0;
  forr(i,1,p)
   g[i]=1;
  ans=max(ans,dp(0,g));
  if(ans>0.0)
  {
    double w=ans/100+(ans%100)*1.0/100;
    printf("Daniel can save $%.2f\n",w);
  }
  else
    printf("Don't leave the house\n");


}
return 0;
}
