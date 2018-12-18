/*
   first we get min spanning tree of our graph and then from any special node we will get distant
   to all other special node and the answer will be max distant

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
int n,m,k,u[100010],v[100010],c[100010],b[100010],dis[100010],ran[100010],p[100010],vis[100010],id[100010];
vector<pair<int,int>>a[100010];
void dfs(int s)
{
    vis[s]=1;
    for(auto p:a[s])
    {
      if(vis[p.F]==0)
      {
      dis[p.F]=max(dis[s],p.S);
      dfs(p.F);
      }
    }
}
bool com (int i,int j)
{
    if(c[i]<c[j])return 1;
    return 0;
}

int findset(int f)
{
    if(p[f]==f)
        return f;
    else
        return p[f]=findset(p[f]);
}
void conect(int x,int y)
{
    x=findset(x);
    y=findset(y);
    if(ran[x]>ran[y])swap(x,y);
    p[x]=y;
    if(ran[x]==ran[y])
        ran[y]++;
}
bool isconect(int x,int y)
{
    if(findset(x)==findset(y))
        return 1;
    else
        return 0;
}
int main()
{

//cout<<Pow((ll)1000000,(ll)110);a
//freopen("trip.in","r",stdin);
//freopen("trip.out","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
cin>>n>>m>>k;

forr(i,1,k)
cin>>b[i];

forr(i,1,m)
{
    cin>>u[i]>>v[i]>>c[i];
    id[i]=i;
}
sort(id+1,id+m+1,com);

forr(i,1,n)p[i]=i;

forr(j,1,m)
{
   int i=id[j];
   if(isconect(u[i],v[i]))continue;

   conect(u[i],v[i]);
   a[u[i]].push_back({v[i],c[i]});
   a[v[i]].push_back({u[i],c[i]});
}
fill(dis,dis+n+2,1e9+9);
dis[b[1]]=0;
dfs(b[1]);
int ans=0;
forr(i,2,k)
ans=max(ans,dis[b[i]]);

forr(i,1,k)
cout<<ans<<" ";
return 0;
}
