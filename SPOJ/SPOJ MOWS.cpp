/*
   we need to get SCC that has max number of  places of interest and has at least 1 hotel .
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
const int N=20005,M=100000;
const double EPS= 1e-8;


int t,h,p,s,comps,compid[200000],lo[200000],cur,vis[200000];
vector<int>a[200000];
stack<int>k;

void dfs(int u)
{
    vis[u]=lo[u]=cur++;
    k.push(u);
    for(auto v:a[u])
    {
        if(vis[v]==-1)
        {
            dfs(v);
            lo[u]=min(lo[u],lo[v]);
        }
        else if(compid[v]==-1)
            lo[u]=min(lo[u],lo[v]);
    }
    if(vis[u]==lo[u])
    {
        int f;
        do{
            f=k.top();
            compid[f]=comps;
            k.pop();
        }while(f!=u);
        comps++;
    }
}
void go()
{
    memset(vis,-1,(1005+p)*sizeof vis[0]);
    memset(compid,-1,(1005+p)*sizeof compid[0]);
    cur=comps=0;
    forr(i,1,h)
        if(vis[i]==-1)dfs(i);
    forr(i,1,p)
        if(vis[i+1000]==-1)dfs(i+1000);
}
 int main()
{

input;

cin>>t;
while(t--)
{
    cin>>h>>p>>s;
    forr(i,1,h)a[i].clear();
    forr(i,1,p)a[i+1000].clear();
    int u,v;
    forr(i,1,s)
    {
        cin>>u>>v;
        a[u].push_back(v);
    }
    go();
    map<int,int>m;
    forr(i,1,p)m[compid[i+1000]]++;
    int ans=0,x=1;
    forr(i,1,h)
    {
        if(m[compid[i]]>ans)
        {
            ans=m[compid[i]];
            x=i;
        }
    }
    cout<<x<<" "<<m[compid[x]]<<endl;

}



return 0;
}
