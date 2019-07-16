/*
    first we need to get the SCC of our graph then in each source component we will take the node with min cost
    and add it to our answer because this nodes must be in our answer to make sure that we can reach any other
    nodes from those nodes .
    then we will sort the other nodes according to there costs in increasing order ,then iterate in them
    if one of them will decrease our average we will add it to the answer .

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


int head[N], nxt[M], to[M], ne, n,compid[N],comps,mn[N],notsrc[N],id[N];
int lo[N],vis[N],cur,w[M],x,dis[N];
stack<int>k;
void init(){
  memset(head, -1, n*sizeof head[0]);
  ne = 0;
}

void addedge(int f, int t){
  to[ne] = t;
  nxt[ne] = head[f];
  head[f] = ne++;
}

void dfs(int u)
{
    lo[u]=vis[u]=cur++;
    k.push(u);
    for(int e=head[u];~e;e=nxt[e])
    {
        int v=to[e];
        if(vis[v]==-1)
        {
            dfs(v);
            lo[u]=min(lo[u],lo[v]);
        }
        else if(compid[v]==-1)lo[u]=min(lo[u],lo[v]);
    }
    if(lo[u]==vis[u])
    {
        int f;
        do{
            f=k.top();
            k.pop();
            compid[f]=comps;
        }while(f!=u);
        comps++;
    }
}


class AntarcticaPolice{
public:
    double minAverageCost(vector <int> costs, vector <string> roads){
        n=costs.size();
        init();
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(roads[i][j]=='Y')addedge(i,j);
        memset(vis,-1,n*sizeof vis[0]);
        memset(compid,-1,n*sizeof compid[0]);
        memset(mn,'?',n*sizeof mn[0]);
        cur=comps=0;
        for(int i=0;i<n;i++)if(vis[i]==-1)dfs(i);

        for(int u=0;u<n;u++)
        {
            for(int e=head[u];~e;e=nxt[e])
            {
                int v=to[e];
                int a=compid[u];
                int b=compid[v];
                if(a!=b)notsrc[b]=1;
            }
        }
        for(int i=0;i<n;i++)
        {
            int a=compid[i];
            if(costs[i]<mn[a])
            {
                mn[a]=costs[i];
                id[a]=i;
            }
        }

        ll ans=0,c=0;
        for(int i=0;i<comps;i++)if(!notsrc[i])ans+=mn[i],c++;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)v.push_back({costs[i],i});
        sort(v.begin(),v.end());

        for(int j=0;j<n;j++)
        {
            int i=v[j].S;
            int a=compid[i];
            if(id[a]==i&&!notsrc[a])continue;
            if((ans+(ll)costs[i])*c<=ans*(c+1))ans+=costs[i],c++;
        }
        return ans*1.0/c*1.0;

    }
};
