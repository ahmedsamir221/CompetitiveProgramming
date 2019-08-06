/*
   the exist of of 'U' ans 'L' cells  make cycles in the graph so we can not use dp forward .
   to handle this cycles we can get the SCC then make every component as a one cell then use dp to get
   the answer .  
*/
#pragma GCC optimize("O3")
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

const int N=25,M=1000000;
const double EPS= 1e-9;
int n,m;
char a[N][N];
int compid[N][N],vis[N][N],low[N][N],cur,comps;
stack<pair<int,int>>k;
void dfs(int i,int j)
{
    vis[i][j]=low[i][j]=cur++;
    k.push({i,j});
    if(i<n)
    {
        if(a[i+1][j]!='#'&&vis[i+1][j]==-1)
        {
         dfs(i+1,j);
         low[i][j]=min(low[i][j],low[i+1][j]);
        }
        else if(a[i+1][j]!='#'&&compid[i+1][j]==-1)low[i][j]=min(low[i][j],low[i+1][j]);
    }
    if(j<m)
    {
        if(a[i][j+1]!='#'&&vis[i][j+1]==-1)
        {
         dfs(i,j+1);
         low[i][j]=min(low[i][j],low[i][j+1]);
        }
        else if(a[i][j+1]!='#'&&compid[i][j+1]==-1)low[i][j]=min(low[i][j],low[i][j+1]);
    }
    if(i>1&&a[i][j]=='U')
    {
        if(a[i-1][j]!='#'&&vis[i-1][j]==-1)
        {
         dfs(i-1,j);
         low[i][j]=min(low[i][j],low[i-1][j]);
        }
        else if(a[i-1][j]!='#'&&compid[i-1][j]==-1)low[i][j]=min(low[i][j],low[i-1][j]);
    }
    if(j>1&&a[i][j]=='L')
    {
        if(a[i][j-1]!='#'&&vis[i][j-1]==-1)
        {
         dfs(i,j-1);
         low[i][j]=min(low[i][j],low[i][j-1]);
        }
        else if(a[i][j-1]!='#'&&compid[i][j-1]==-1)low[i][j]=min(low[i][j],low[i][j-1]);
    }

    if(low[i][j]==vis[i][j])
    {
        pair<int,int>p={1,1};
        do
        {
            p=k.top();
            k.pop();
            compid[p.F][p.S]=comps;
        }while(p!=make_pair(i,j));
        comps++;
    }
}

void go()
{
    memset(vis,-1,sizeof vis);
    memset(compid,-1,sizeof compid);
    cur=comps=0;
    forr(i,1,n)
    forr(j,1,m)
    {
        if(vis[i][j]==-1&&a[i][j]!='#')dfs(i,j);
    }
}

int mem[N][N][N*N];
int dp(int i=1,int j=1,int p=401)
{
    if(i>n||j>m)return 0;
    int&ret=mem[i][j][p];
    if(~ret)return ret;
    ret=0;
    int c=0;
    forr(u,1,n)
    forr(v,1,m)
    if(compid[i][j]==compid[u][v]&&a[u][v]!='L'&&a[u][v]!='U')c+=a[u][v]-'0';

    forr(u,1,n)
    forr(v,1,m)
    {
        if(compid[i][j]==compid[u][v])
            ret=max(ret,dp(u,v,compid[i][j])+(compid[i][j]==p?0:c));
    }

    if(a[i+1][j]!='#')ret=max(ret,dp(i+1,j,compid[i][j])+(compid[i][j]==p?0:c));
    if(a[i][j+1]!='#')ret=max(ret,dp(i,j+1,compid[i][j])+(compid[i][j]==p?0:c));

    return ret;
}

class MarbleCollectionGame{
public:
    int collectMarble(vector <string> board){
        n=board.size();
        m=board[0].size();
        forr(i,1,n)
        forr(j,1,m)
        a[i][j]=board[i-1][j-1];
        go();
        memset(mem,-1,sizeof mem);
        return dp();
    }
};
