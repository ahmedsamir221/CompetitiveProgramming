/*
   first we want to know every cell that we can make the path to it contain 'a' only
   we can do that with BFS
   then start from this cells that have max distance then try to Find the lexicographically smallest string
   we can do that with set and BFS;
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
int n,k,dis[2002][2002],c[2002][2002],mx;
char a[2002][2002];

void dfs(int i,int j)
{
    queue<pair<int,int>>q;
    q.push({1,1});
    while(q.size())
    {
    i=q.front().F;
    j=q.front().S;
    q.pop();
    if(c[i][j]+k>=dis[i][j]-1&&dis[i][j]>mx)
        mx=dis[i][j];
    if(i==n&&j==n)continue;
    int t=0;
    if(a[i][j]=='a')t=1;
    if(i+1<=n&&(dis[i+1][j]==0||c[i+1][j]<c[i][j]+t))
    {
        c[i+1][j]=c[i][j]+t;
        dis[i+1][j]=dis[i][j]+1;
       q.push({i+1,j});
    }
    if(j+1<=n&&(dis[i][j+1]==0||c[i][j+1]<c[i][j]+t))
    {
        c[i][j+1]=c[i][j]+t;
        dis[i][j+1]=dis[i][j]+1;
        q.push({i,j+1});
    }
    }
}
set<pair<char,pair<int,int>>>s[2];
string ans;
void get()
{
    int r=0;
    while(1)
    {
        auto t=*s[r].begin();
        ans.push_back(t.F);
        if(t.S.F==n&&t.S.S==n)break;
        for(auto p:s[r])
        {
            if(p.F==t.F)
            {
                if(p.S.F+1<=n)
                    s[!r].insert({a[p.S.F+1][p.S.S],{p.S.F+1,p.S.S}});
                if(p.S.S+1<=n)
                    s[!r].insert({a[p.S.F][p.S.S+1],{p.S.F,p.S.S+1}});

            }
        }
        s[r].clear();
        r=!r;
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
cin>>n>>k;
forr(i,1,n)
forr(j,1,n)
cin>>a[i][j];

dis[1][1]=1;
dfs(1,1);
if(mx==n*2-1&&k+mx-1>=n*2-1)
{
    forr(i,1,mx)cout<<"a";
    return 0;
}
forr(i,1,n)
forr(j,1,n)
{
    if(dis[i][j]==mx&&c[i][j]+k>=dis[i][j]-1)
    {
        s[0].insert({a[i][j],{i,j}});
    }
}
get();
forr(i,1,mx-1)cout<<"a";
cout<<ans;
return 0;
}
