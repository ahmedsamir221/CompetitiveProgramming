/*
   first we will root the tree from any node , then flat it in such away that we will give it's index when we
   leave it in the DFD ,for each node we will keep the min and the max index in it's subtree ,
   and we need also to get the distance from the root to all other nodes .
   if the node is marked we will put it's value = distance from the root , otherwise it's value = -infinity
   then build max segment tree in our new array ,then start new DFS to get our answer .
   if we will visit node X in the DFS except the root some nodes it'S distance  to X will decrease by one and
   the other will increase by one , the nodes that will decrease it's the nodes in the subtree of X .
   so we can update our segment tree according to that and also get max value till now to check the current node .
   and when we leave node X we will undo our update .

*/
#pragma GCC optimize("O3")
#include<queue>
#include <cmath>
#include <complex>
#include<map>
#include <string>
#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <stdio.h>
#include<bits/stdc++.h>


#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);


const double PI  = acos(-1.0);
using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
typedef complex<double> point;

//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
const int N=100007,M=1000000;
const double EPS= 1e-9;

int n,m,d,k[N],id[N],lft[N],rt[N],e,dis[N],val[N*20],laz[N*20],a[N];
int l,r,x,ans;
vector<int >adj[N];
int bulid(int s=1,int e=n,int p=1)
{
    if(s==e)return val[p]=a[s];
    int mid=(s+e)/2;
    return val[p]=max(bulid(s,mid,p*2),bulid(mid+1,e,p*2+1));
}
void dolaz(int p)
{
    val[p*2]+=laz[p];
    laz[p*2]+=laz[p];
    val[p*2+1]+=laz[p];
    laz[p*2+1]+=laz[p];
    laz[p]=0;
}
int up(int s=1,int e=n,int p=1)
{
    if(l>r)return 0;
    if(s>=l&&e<=r)
    {
        val[p]+=x;
        laz[p]+=x;
        return val[p];
    }
    dolaz(p);
    int mid=(s+e)/2;
    if(r<=mid)return val[p]=max(up(s,mid,p*2),val[p*2+1]);
    else if(l>mid)return val[p]=max(val[p*2],up(mid+1,e,p*2+1));
    else return val[p]=max(up(s,mid,p*2),up(mid+1,e,p*2+1));
}

int get(int s=1,int e=n,int p=1)
{
    if(s>=l&&e<=r)return val[p];
    dolaz(p);
    int mid=(s+e)/2;
    if(r<=mid)return get(s,mid,p*2);
    else if(l>mid)return get(mid+1,e,p*2+1);
    else return max(get(s,mid,p*2),get(mid+1,e,p*2+1));
}

void dfs(int u,int p)
{
    int cnt=0;
    for(auto v:adj[u])
    {
        if(v==p)continue;
        cnt++;
        dis[v]=dis[u]+1;
        dfs(v,u);
    }
    id[u]=++e;
    if(cnt==0)lft[id[u]]=rt[id[u]]=id[u];
    else{
    for(auto v:adj[u])
    {
        if(v==p)continue;
        lft[id[u]]=min(lft[id[u]],lft[id[v]]);
        rt[id[u]]=max(rt[id[u]],rt[id[v]]+1);
    }}
}

void go(int u,int p)
{
    l=1,r=n;
    int g=get();
    if(g<=d)ans++;
   // cout<<u<<" "<<id[u]<<" "<<g<<endl;
    for(auto v:adj[u])
    {
        if(v==p)continue;
        int i=lft[id[v]],j=rt[id[v]];
      //   cout<<u<<" "<<v<<" "<<i<<" "<<j<<endl;
        l=1,r=i-1,x=1,up();
        l=i,r=j,x=-1,up();
        l=j+1,r=n,x=1,up();
        go(v,u);
        l=1,r=i-1,x=-1,up();
        l=i,r=j,x=1,up();
        l=j+1,r=n,x=-1,up();
    }

}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;
cin>>n>>m>>d;
forr(i,1,m)cin>>k[i];
int u,v;
forr(i,1,n-1)
{
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
dis[1]=0;
memset(lft,'?',sizeof lft);
memset(rt,0,sizeof rt);
dfs(1,-1);
map<int,int>ck;
forr(i,1,m)
{
    u=id[k[i]];
    a[u]=dis[k[i]];
    ck[u]=1;
}
forr(i,1,n)
    if(ck.count(i)==0)a[i]=-1e9;

bulid();

go(1,-1);
cout<<ans<<endl;


return 0;
}
