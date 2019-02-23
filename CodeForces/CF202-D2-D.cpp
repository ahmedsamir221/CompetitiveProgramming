//http://http://codeforces.com/blog/entry/4808
#include <iostream>
#include<vector>
#include<algorithm>
//#include <cmath>
//#include <complex>
#include<queue>
#include<map>
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
//typedef bitset<30> mask;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//const double PI = acos(-1.0);
//const double EPS = 1e-9;
//typedef complex<double> point;
ll n,m,a[1003][1003];
ll sumx[1003][1003],sumy[1003][1003];
ll ansx=1e18,x,ansy=1e18,y;
int main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
cin>>n>>m;
forr(i,1,n)
forr(j,1,m)cin>>a[i][j];

forr(i,1,n)
forr(j,1,m)
sumx[i][j]=a[i][j]+sumx[i][j-1];


forr(j,1,m)
forr(i,1,n)
sumy[i][j]=a[i][j]+sumy[i-1][j];


forr(i,0,n)
{
  ll X=(ll)i*4;
  ll g=0;
  for(ll j=2,k=1;k<=n;j+=4,k++)
  {
      ll tx=j;
      g+=sumx[k][m]*(X-tx)*(X-tx);
  }
  if(g<ansx)
  {
      ansx=g;
      x=i;
  }
}



forr(i,0,m)
{
  ll Y=(ll)i*4;
  ll g=0;
  for(ll j=2,k=1;k<=m;j+=4,k++)
  {
      ll ty=j;
      g+=sumy[n][k]*(Y-ty)*(Y-ty);
  }
  if(g<ansy)
  {
      ansy=g;
      y=i;
  }
}
cout<<ansx+ansy<<endl;
cout<<x<<" "<<y;
return 0;
}
