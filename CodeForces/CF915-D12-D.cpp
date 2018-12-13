/*
     https://codeforces.com/blog/entry/57123
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
int n,m,u,v,vis[505],ck[505],pr[505],h,from,to;
vector<int>a[505];
vector<pair<int,int>>cycle;

void bulid(int i,int d)
{
    if(i==d)return;
    cycle.push_back({pr[i],i});
    bulid(pr[i],d);
}
void dfs(int nod)
{
  vis[nod]=1;
  ck[nod]=1;
  for(auto p:a[nod])
  {
     if(vis[p]==0)
      {
        pr[p]=nod;
        dfs(p);
      }
      else if(ck[p]==1)
      {
          cycle.push_back({nod,p});
          bulid(nod,p);
          h=1;
      }
     if(h==1)
       return;
  }
  ck[nod]=0;
}


void is_cycle(int nod)
{
  vis[nod]=1;
  ck[nod]=1;
  if(h==1)
    return;
  for(auto p:a[nod])
  {
      if(nod==from&&p==to)continue;
      if(ck[p]==1)
      {
          h=1;
          break;
      }
      else if(vis[p]==0)
          is_cycle(p);

  }
  ck[nod]=0;
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
forr(i,1,m)
{
    cin>>u>>v;
    a[u].push_back(v);
}
forr(i,1,n)
  if(vis[i]==0&&h==0)
      dfs(i);

if(h==0)
    cout<<"YES";
else
{
    for(auto k:cycle)
    {
        from=k.F;
        to=k.S;
        //cout<<from<<"   "<<to<<endl;
        h=0;
        memset(vis,0,sizeof vis);
        memset(ck,0,sizeof ck);

        forr(i,1,n)
         if(vis[i]==0&&h==0)
           is_cycle(i);

        if(h==0)
        {
           cout<<"YES";
           return 0;
        }
    }
    cout<<"NO";
}
return 0;
}
