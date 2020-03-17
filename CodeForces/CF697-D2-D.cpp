/*
    the answer of each node is (minTime + maxTime )/2  the time which the node can be assigned .
*/
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#include<map>
#include<iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);

//const double PI  = acos(-1.0);
using namespace std;
//typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
//typedef complex<double> point;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//char rv[4]={'D','R','L','U'};
const double EPS = 1e-9;
const int N = 5e5 + 9;
int n,vis[N],mn[N],mx[N];
vector<int>adj[N];

void dfs(int u)
{
    vis[u]=1;
    for(auto v:adj[u])
    {
        if(vis[v])continue;
        mn[v]=mn[u]+1;
        dfs(v);
        mx[u]+=mx[v];
    }
    mx[u]++;
}
 int main()
{
//freopen("circles.in ","r",stdin);
//freopen("circles.out","w",stdout);
//__builtin_popcount()
input
        cin>>n;
        int p;
        forr(i,2,n)
        {
            cin>>p;
            adj[p].push_back(i);
        }
        mn[1]=1;
        dfs(1);
        forr(i,1,n)
            cout<<fixed<<setprecision(6)<<(mn[i]+(n-mx[i]+1))/2.0<<" ";

return 0;
}
