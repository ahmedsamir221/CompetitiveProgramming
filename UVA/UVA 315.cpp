/*
   we need to count the number of articulation points
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
const int N=105,M=100000;
const double EPS= 1e-8;

int n,vis[N],isArt[N],lo[N],cur,root,ckroot;
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
                else isArt[u]=1;
            }
            else if(lo[v]>=vis[u])isArt[u]=1;
        }
        else lo[u]=min(lo[u],vis[v]);
    }
}

int go()
{
    memset(vis,-1,(n+1)*sizeof vis[0]);
    memset(isArt,0,(n+1)*sizeof isArt[0]);
    cur=0;
    int ans=0;
    forr(i,1,n)
    {
        if(vis[i]==-1)root=i,ckroot=0,dfs(i,-1);
        if(isArt[i])ans++;
    }
    return ans;
}
 int main()
{

input;

while(cin>>n,n)
{
    string s;
    getline(cin,s);
    forr(i,1,n)a[i].clear();
    while(getline(cin,s),s!="0")
    {
        stringstream f;
        f<<s;
        int u,v;
        f>>u;
        while(f>>v)
        {
            a[u].push_back(v);
            a[v].push_back(u);
        }
    }
    cout<<go()<<endl;
}
return 0;
}
