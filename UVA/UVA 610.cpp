/*
   only the bridges will have two ways , other edges will set it's direction by DFS .
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
const int N=5005,M=1000000;
const double EPS= 1e-8;
int n,m,lo[N],vis[N],cur;
int head[N],nxt[M],to[M],ne,bob[M];
vector<pair<int,int>>ans;
void init()
{
    memset(head,-1,(n+1)*sizeof head[0]);
    ne=0;
}
void addedge(int f,int t)
{
    to[ne]=t;
    nxt[ne]=head[f];
    head[f]=ne++;
}

void dfs(int u)
{
    lo[u]=vis[u]=cur++;
    for(int e=head[u];~e;e=nxt[e])
    {
        int v=to[e];
        if(bob[e])continue;
        if(vis[v]==-1)
        {
            bob[e]=1;
            bob[e^1]=1;
            dfs(v);
            lo[u]=min(lo[u],lo[v]);
            if(lo[v]>vis[u])ans.push_back({v,u});
        }
        else lo[u]=min(lo[u],vis[v]),bob[e]=1,bob[e^1]=1;
        ans.push_back({u,v});
    }
}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
input;
int cas=0;
while(cin>>n>>m,n||m)
{
    init();
    int u,v;
    forr(i,1,m)
    {
        cin>>u>>v;
        addedge(u,v);
        addedge(v,u);
    }
    memset(vis,-1,(n+1)*sizeof vis[0]);
    memset(bob,0,(ne+1)*sizeof bob[0]);
    cur=0;
    ans.clear();
    dfs(1);
    cout<<++cas<<endl<<endl;
    for(auto f:ans)cout<<f.F<<" "<<f.S<<endl;
    cout<<"#"<<endl;
}
return 0;
}
