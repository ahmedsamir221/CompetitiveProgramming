/*
   the answer is the max between the number of sources SCC and  the number of sinks SCC .
   except when there is one component the answer is zero .
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


int t,n,m,comps,compid[200000],lo[200000],cur,vis[200000],notsrc[200000],notsnk[200000];
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
int go()
{
    memset(vis,-1,(n+1)*sizeof vis[0]);
    memset(compid,-1,(n+1)*sizeof compid[0]);
    memset(notsrc,0,(n+1)*sizeof notsrc[0]);
    memset(notsnk,0,(n+1)*sizeof notsnk[0]);
    cur=comps=0;
    forr(i,1,n)
        if(vis[i]==-1)dfs(i);
    forr(u,1,n)
    {
        for(auto v:a[u])
        {
            if(compid[u]!=compid[v])
            {
                notsnk[compid[u]]=1;
                notsrc[compid[v]]=1;
            }
        }
    }
    int snk=comps,src=comps;
    forr(i,0,comps-1)
    {
        if(notsnk[i])src--;
        if(notsrc[i]) snk--;
    }
    if(comps==1)return 0;
    return max(src,snk);
}
 int main()
{

input;

cin>>t;
while(t--)
{
    cin>>n>>m;
    forr(i,1,n)a[i].clear();
    int u,v;
    forr(i,1,m)
    {
        cin>>u>>v;
        a[u].push_back(v);
    }
    cout<<go()<<endl;
}



return 0;
}
