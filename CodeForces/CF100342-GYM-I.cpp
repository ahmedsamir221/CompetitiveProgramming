/*
   we need to know for each articulation point in graph the sizes of component when it extract's from the graph .
   so we can do that by tarjan then calculate the number of pairs
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
const double EPS= 1e-8;

int n,m,vis[N],isArt[N],lo[N],cur,root,ckroot,sum[N],c[N];
ll ans[N];
int nxt[M],to[M],head[N],ne;

void add_edge(int f,int t)
{
    to[ne]=t;
    nxt[ne]=head[f];
    head[f]=ne++;
}
void dfs(int u,int p)
{
    vis[u]=lo[u]=cur++;
    for(int e=head[u];~e;e=nxt[e])
    {
        int v=to[e];
        if(e==p) continue;
        if(vis[v]==-1)
        {
            dfs(v,e^1);
            c[u]+=c[v];
            lo[u]=min(lo[u],lo[v]);
            if(u==root)
            {
                if(!ckroot)ckroot=1;
                else
                {
                    ans[u]+=(ll)sum[u]*(ll)c[v];
                    sum[u]+=c[v];
                }
            }
            else if(lo[v]>=vis[u])
            {
                ans[u]+=(ll)sum[u]*(ll)c[v];
                sum[u]+=c[v];
            }
        }
        else lo[u]=min(lo[u],vis[v]);
    }
    c[u]++;
}

 int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
input;
cin>>n>>m;
memset(head,-1,(n+1)*sizeof head[0]);
int u,v;
forr(i,1,m)
{
    cin>>u>>v;
    add_edge(u,v);
    add_edge(v,u);
}
memset(vis,-1,(n+1)*sizeof vis[0]);
cur=0;
root=1;
dfs(1,-1);
forr(i,1,n)cout<<(ll)(n-1-sum[i])*(ll)sum[i]+ans[i]+(ll)(n-1)<<endl;
return 0;
}
