//https://codeforces.com/blog/entry/60288
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
const double EPS= 1e-8;


int head[N], nxt[M], to[M], ne, n,m,mx;
int lo[N],vis[N],cur,w[M],x,dis[N];

void init(){
  memset(head, -1, (n+1)*sizeof head[0]);
  memset(vis, -1, (n+1)*sizeof vis[0]);
  ne = 0;
}

void addedge(int f, int t){
  to[ne] = t;
  nxt[ne] = head[f];
  head[f] = ne++;
}

void tarjan(int u,int p)
{
    lo[u]=vis[u]=cur++;
    for(int e=head[u];~e;e=nxt[e])
    {
        if(e==p)continue;
        int v=to[e];
        if(vis[v]==-1)
        {
            tarjan(v,e^1);
            lo[u]=min(lo[u],lo[v]);
            if(lo[v]>vis[u])w[e]=1,w[e^1]=1;
        }
        else lo[u]=min(lo[u],vis[v]);
    }
}


void dfs(int u)
{
    if(dis[u]>mx)
    {
        mx=dis[u];
        x=u;
    }
    for(int e=head[u];~e;e=nxt[e])
    {
        int v=to[e];
        if(dis[v]==-1)
        {
            dis[v]=dis[u]+w[e];
            dfs(v);
        }
    }
}

 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
input;
cin>>n>>m;
init();
int u,v;
forr(i,1,m)
{
    cin>>u>>v;
    addedge(u,v);
    addedge(v,u);
}
tarjan(1,-1);

memset(dis,-1,(n+1)*sizeof dis[0]);
dis[1]=0;
dfs(1);
mx=0;
memset(dis,-1,(n+1)*sizeof dis[0]);
dis[x]=0;
dfs(x);
cout<<dis[x]<<endl;

return 0;
}
