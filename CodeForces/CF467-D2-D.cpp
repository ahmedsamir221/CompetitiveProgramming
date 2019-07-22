/*
     we need to build a graph the nodes are the words and between every pair X , Y edge from X to Y .
     then try from every word of the essay to replace it with min word that is reachable from it .
     so we can do that be DFS .
     to avoid the cycles and the loops we can do two DFS from both sides of the essay (may it just by luck) .

*/
#include<queue>
#include <cmath>
#include <complex>
#include<map>
#include <string>
#include<iostream>
#include<bits/stdc++.h>


#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);


using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
typedef complex<double> point;
//template<typename T>T gcd(T x, T y) { if(y == 0)return x; else return gcd(y, x%y); }
//typedef bitset<30> mask;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//#define var(x) ((x)<<1)
//#define nvar(x) ((x)^1)
const int N=500005,M=1000000;
const double EPS= 1e-9;

int n,m;
string a[100010];
map<string ,pair<int,string>>ck;
map<string,vector<string>>adj;
map<string,int>vis;

void get(string u)
{
    vis[u]=1;
    for(auto v:adj[u])
    {
        if(vis.count(v)==0)get(v);
        if(ck[v].F<ck[u].F||(ck[v].F==ck[u].F&&ck[v].S.size()<ck[u].S.size()))ck[u]=ck[v];
    }
}

 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
input;
cin>>n;
forr(i,1,n)
{
  cin>>a[i];
  for(int j=0;j<a[i].size();j++)a[i][j]=tolower(a[i][j]);
  int c=0;
  for(auto p:a[i])if(p=='r')c++;
  ck[a[i]]={c,a[i]};
}
string x,y;
cin>>m;
forr(i,1,m)
{
    cin>>x>>y;
    for(int j=0;j<x.size();j++)x[j]=tolower(x[j]);
    for(int j=0;j<y.size();j++)y[j]=tolower(y[j]);
    int c1=0,c2=0;
    for(auto p:x)if(p=='r')c1++;
    for(auto p:y)if(p=='r')c2++;
    ck[x]={c1,x};
    ck[y]={c2,y};
    adj[x].push_back(y);
}
for(int i=1;i<=n;i++) if(vis.count(a[i])==0)get(a[i]);
vis.clear();
for(int i=n;i>=1;i--) if(vis.count(a[i])==0)get(a[i]);
ll ans1=0,ans2=0;
for(int i=1;i<=n;i++)
{
    ans1+=ck[a[i]].F;
    ans2+=ck[a[i]].S.size();
}
cout<<ans1<<" "<<ans2;
return 0;
}
