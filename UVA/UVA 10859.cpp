//https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/UVA/UVA_10859.txt
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


/*
#define x real()
#define y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))
*/

//#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);
#define NOT(x) (1^x)

const double PI  = acos(-1.0);
using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
typedef complex<double> point;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
const int N = 2e6 + 3, M = 5e4 + 3;
int n,m,id,vis[1006];
pair<int,int>mem[1006][2];
vector<int>adj[1006];
void dfs(int u)
{
    vis[u]=id;
    for(auto v:adj[u])
    {
        if(vis[v]==id)continue;
        dfs(v);
    }
}

pair<int,int> dp(int u,int p,int ck)
{
    pair<int,int>&ret=mem[u][ck];
    if(ret.F!=-1)return ret;
    if(ck)
    {
        pair<int,int>g={0,0};
        for(auto v:adj[u])
        {
            if(v==p)continue;
            pair<int,int> k=dp(v,u,0);
            g.F+=k.F,g.S+=k.S;
        }
        g.F++;
        g.S++;
        return ret=g;
    }
    else
    {
        pair<int,int>g1={0,0},g2={0,0};
        for(auto v:adj[u])
        {
            if(v==p)continue;
            pair<int,int> k1=dp(v,u,1);g1.F+=k1.F,g1.S+=k1.S;
            pair<int,int> k2=dp(v,u,0);g2.F+=k2.F,g2.S+=k2.S;
        }
        if(p!=-1)g1.S++;
        g2.F++;
        return ret=min(g1,g2);
    }
}

 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)adj[i].clear();
        int u,v;
        for(int i=0;i<m;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        pair<int,int>ans={0,0};
        id++;
        for(int i=0;i<n;i++)
        {
            if(vis[i]!=id)
            {
                dfs(i);
                memset(mem,-1,sizeof mem);
                pair<int,int>k=dp(i,-1,0);
                ans.F+=k.F;
                ans.S+=k.S;
            }
        }
        cout<<ans.F<<" "<<m-ans.S<<" "<<ans.S<<endl;
    }

return 0;
}
