/*
   we need to get the bridges of our graph
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
const int N=500005,M=100000;
const double EPS= 1e-8;

int n,m,vis[N],isArt[N],lo[N],cur,root,ckroot;
vector<int>a[N];
vector<pair<int,int>>brd;
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
            if(lo[v]>vis[u])brd.push_back({min(u,v),max(u,v)});
        }
        else lo[u]=min(lo[u],vis[v]);
    }
}

vector<pair<int,int>> go()
{
    memset(vis,-1,(n+1)*sizeof vis[0]);
    brd.clear();
    cur=0;
    forr(i,0,n-1) if(vis[i]==-1) dfs(i,-1);
    sort(brd.begin(),brd.end());
    return brd;
}
 int main()
{

input;

while(cin>>n)
{
    forr(i,0,n-1)a[i].clear();
    int u,v,k;
    char ch;
    forr(i,1,n)
    {
        cin>>u>>ch>>k>>ch;
        forr(j,1,k)
        {
            cin>>v;
            a[u].push_back(v);
        }
    }
    vector<pair<int,int>>ans=go();
    cout<<(int)ans.size()<<" critical links"<<endl;
    for(auto p:ans)cout<<p.F<<" - "<<p.S<<endl;
    cout<<endl;
}
return 0;
}
