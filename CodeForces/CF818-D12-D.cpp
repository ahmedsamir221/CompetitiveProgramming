/*
first we will assume the button with normal direction
because we start with cell(1,1) there must be at least two cell to check the button safely
so we get path to the end using DFS then we use this path and at any moment the input deffer
from our path we will swap the direction and continue from current cell again until
reach to our end
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
//typedef bitset<21> mask;
int x[8]={1,0,0,-1,-1,-1,1,1};
int y[8]={0,1,-1,0,-1,1,-1,1};
//const double PI = acos(-1.0);
//const double EPS = 1e-9;
//typedef complex<double> point;
int n,m,vis[110][110],ex,ey,xx,yy;
pair<int,int>pr[110][110];
char a[110][110],u='U',d='D',l='L',r='R';
vector<pair<int,int>>path;
bool valid (int i,int j)
{
    if(i<1||i>n||j<1||j>m)return 0;
    return 1;
}
void dfs(int i,int j)
{
   vis[i][j]=1;
   forr(k,0,3)
   {
     int u=x[k]+i;
     int v=y[k]+j;
     if(vis[u][v]==0&&valid(u,v)&&a[u][v]!='*')
     {
        pr[u][v]={i,j};
        dfs(u,v);
     }
   }
}
void bulid(int i=ex,int j=ey)
{
    if(i==1&&j==1)return;
    bulid(pr[i][j].F,pr[i][j].S);
    path.push_back({i,j});
}
int main()
{

//cout<<Pow((ll)1000000,(ll)110);a
//freopen("tour.in","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
cin>>n>>m;
forr(i,1,n)
forr(j,1,m)
{
cin>>a[i][j];
if(a[i][j]=='F')
    ex=i,ey=j;
}

dfs(1,1);
bulid(ex,ey);
int curx=1,cury=1;
forr(i,0,(int)path.size()-1)
{
if(path[i].F>curx)
{
    cout<<d<<endl;
    fflush(stdout);
    cin>>xx>>yy;
    if(path[i]!=make_pair(xx,yy))
      {
          swap(d,u);
          i--;
      }
    else
        curx++;
}
else if(path[i].F<curx)
{
    cout<<u<<endl;
    fflush(stdout);
    cin>>xx>>yy;
    if(path[i]!=make_pair(xx,yy))
      {
          swap(d,u);
          i--;
      }
    else
        curx--;
}
else if(path[i].S>cury)
{
    cout<<r<<endl;
    fflush(stdout);
    cin>>xx>>yy;
    if(path[i]!=make_pair(xx,yy))
      {
          swap(r,l);
          i--;
      }
    else
        cury++;
}
else
{
    cout<<l<<endl;
    fflush(stdout);
    cin>>xx>>yy;
    if(path[i]!=make_pair(xx,yy))
      {
          swap(l,r);
          i--;
      }
    else
        cury--;
}
}
return 0;
}
