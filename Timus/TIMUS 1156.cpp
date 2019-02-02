/*
   first we will make edge between each problem and it's analogous  then check if
   we can split each component of problems to two parts  or if we can make it bipartite graph
   then use the dp to check if we can construct n problem in each round that not  analogous
*/
#include<stdio.h>
#include<vector>
#include<algorithm>
#include <iostream>
#include <cmath>
#include <complex>
#include<queue>
#include <string>
#include<bits/stdc++.h>
#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);
//#define x real()
//#define y imag()
using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
//typedef complex<double> point;
//template<typename T>T gcd(T x, T y) { if(y == 0)return x; else return gcd(y, x%y); }
//typedef bitset<30> mask;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//const double PI = acos(-1.0);
//const double EPS = 1e-9;
//typedef complex<double> point;
int n,m,ck[105],u,v,bo,vis[105],mem[222][105],b[220];
vector<int>a[220],ans1,ans2;
void dfs(int i)
{
    vis[i]=1;
    for(auto p:a[i])
    {
        if(ck[i]==ck[p])bo=1;

        if(vis[p]==0)
        {
            ck[p]=(ck[i]^1);
            dfs(p);
        }
    }
}

int dp(int i=0,int c=0)
{
    if(i>4*n)
    {
        if(c==n)return 1;
        return 0;
    }
    int&ret=mem[i][c];
    if(~ret)return ret;
    ret=0;
    int c1=dp(i+2,c+b[i]);
    int c2=dp(i+2,c+b[i+1]);
    return ret=max(c1,c2);
}
void bulid(int i=0,int c=0)
{
    if(i>4*n)
    {
        if(c==n)return ;
        return ;
    }

    int c1=dp(i+2,c+b[i]);
    int c2=dp(i+2,c+b[i+1]);
    if(dp(i,c)==c1)
    {
        forr(j,1,n*2)
        {
            if(ck[j]==i)ans1.push_back(j),ck[j]=-1;
        }
        bulid(i+2,c+b[i]);
    }
    else
    {
        forr(j,1,n*2)
        {
            if(ck[j]==i+1)ans1.push_back(j),ck[j]=-1;
        }
        bulid(i+2,c+b[i+1]);
    }
}
int main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("CAMP.IN","r",stdin);
//freopen("CAMP.OUT","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
cin>>n>>m;
forr(i,1,m)
{
    cin>>u>>v;
    a[u].push_back(v);
    a[v].push_back(u);
}
memset(ck,-1,sizeof ck);
int idx=-2;
forr(i,1,2*n)
{
    if(vis[i]==0)
    {
        idx+=2;
        ck[i]=idx;
        dfs(i);
    }
}

forr(i,1,2*n)
b[ck[i]]++;

memset(mem,-1,sizeof mem);
if(bo==0&&dp())
{
    bulid();
    forr(j,1,2*n)if(ck[j]!=-1)ans2.push_back(j);
    for(auto p:ans1)cout<<p<<" ";
    cout<<endl;
    for(auto p:ans2)cout<<p<<" ";
    cout<<endl;
}
else
    cout<<"IMPOSSIBLE"<<endl;

return 0;
}
