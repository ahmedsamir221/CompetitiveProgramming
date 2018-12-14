/*
   we just need to use floyed to get shortest path and number of segments between each pair of cities
   then get its average
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
//typedef bitset<30> mask;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//const double PI = acos(-1.0);
//const double EPS = 1e-9;
//typedef complex<double> point;
ll n,m;
pii adj[303][303];

int main()
{

//cout<<Pow((ll)1000000,(ll)110);a
freopen("trip.in","r",stdin);
freopen("trip.out","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
cin>>n>>m;

forr(i,1,n)
forr(j,1,n)
{
    if(i==j)
      adj[i][j]={0,0};
    else
      adj[i][j]={1e15,1};
}
ll x,y,c;
forr(i,1,m)
{
    cin>>x>>y>>c;
    adj[x][y].F=min(adj[x][y].F,c);
    adj[y][x].F=adj[x][y].F;
}


forr(k,1,n) forr(i,1,n) forr(j,1,n)
  adj[i][j] = min(adj[i][j], make_pair(adj[i][k].F+adj[k][j].F,adj[i][k].S+adj[k][j].S));

ll ans=0;
forr(i,1,n)
forr(j,i+1,n)
ans+=adj[i][j].S;

cout<<fixed<<setprecision(18)<<ans*1.0/(n*(n-1)/2);
return 0;
}
