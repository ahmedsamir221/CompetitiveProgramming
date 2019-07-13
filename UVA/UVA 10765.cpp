/*
   we need to count the number of times each node can be articulation point , then the pigeon value of each city
   will be that number + 1
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
const int N=10005,M=100000;
const double EPS= 1e-8;

int n,m,vis[N],isArt[N],lo[N],cur,root,ckroot;
vector<int>a[N];

void dfs(int u,int p)
{
    vis[u]=lo[u]=cur++;
    for(auto v:a[u])
    {
        if(v==p)continue;
        if(vis[v]==-1)
        {
            dfs(v,u);
            lo[u]=min(lo[u],lo[v]);
            if(u==root)
            {
                if(!ckroot)ckroot=1;
                else isArt[u]++;
            }
            else if(lo[v]>=vis[u])isArt[u]++;
        }
        else lo[u]=min(lo[u],vis[v]);
    }
}

vector<pair<int,int>> go()
{
    memset(vis,-1,(n+1)*sizeof vis[0]);
    memset(isArt,0,(n+1)*sizeof isArt[0]);
    cur=0;
    vector<pair<int,int>> ans;
    forr(i,0,n-1)
    {
        if(vis[i]==-1)root=i,ckroot=0,dfs(i,-1);
        ans.push_back({-isArt[i]-1,i});
    }
    sort(ans.begin(),ans.end());
    return ans;
}
 int main()
{

input;

while(cin>>n>>m,n||m)
{
    forr(i,0,n-1)a[i].clear();
    int u,v;
    while(cin>>u>>v,u!=-1||v!=-1)
    {
        a[u].push_back(v);
        a[v].push_back(u);
    }
    vector<pair<int,int>>ans=go();
    for(int i=0;i<m;i++)cout<<ans[i].S<<" "<<-ans[i].F<<endl;
    cout<<endl;
}
return 0;
}
