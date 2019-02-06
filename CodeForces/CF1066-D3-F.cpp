/*
  we need for each level to save two points that the distance between them is the max in that level
  then use dp to calculate min distance our state will be current level and which point in that level
  and each time we will try to visit the next level from it's two point and add the distance between
  the two levels and the distance between the two point in current level
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
int n,x,y,m;
pair<int,int>u[200020],d[200020];
int dis[200020];
map<int,int>Umn,Umx,Dmn,Dmx,l;

int clc(pair<int,int>i,pair<int,int>j)
{
    return abs(i.F-j.F)+abs(i.S-j.S);
}

ll mem[200020][2];

ll dp(int i=0,int k=0)
{
    if(i==m)return (ll)dis[i];
    ll&ret=mem[i][k];
    if(~ret)return ret;

    pair<int,int>cur;
    if(k==0) cur=d[i];
    else cur=u[i];

    ll c1=dp(i+1,0)+(ll)clc(cur,u[i+1])+(ll)dis[i];
    ll c2=dp(i+1,1)+(ll)clc(cur,d[i+1])+(ll)dis[i];

    return ret=min(c1,c2);
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
cin>>n;
forr(i,1,n)
{
    cin>>x>>y;
    l[max(x,y)]=1;
    if(x>=y)
    {
        if(Dmn.count(x)==0)
        {
            Dmn[x]=2e9;
            Dmx[x]=-2e9;
        }
        Dmn[x]=min(Dmn[x],y);
        Dmx[x]=max(Dmx[x],y);
    }
    if(y>=x)
    {
        if(Umn.count(y)==0)
        {
            Umn[y]=2e9;
            Umx[y]=-2e9;
        }
        Umn[y]=min(Umn[y],x);
        Umx[y]=max(Umx[y],x);
    }

}

for(auto p:l)
{
    m++;
    if(Umn.count(p.F)&&Dmn.count(p.F))
    {
        u[m]={Umn[p.F],p.F};
        d[m]={p.F,Dmn[p.F]};
        dis[m]=clc(u[m],d[m]);
    }
    else if(Umn.count(p.F))
    {
        u[m]={Umn[p.F],p.F};
        d[m]={Umx[p.F],p.F};
        dis[m]=clc(u[m],d[m]);
    }
    else if(Dmn.count(p.F))
    {
        u[m]={p.F,Dmx[p.F]};
        d[m]={p.F,Dmn[p.F]};
        dis[m]=clc(u[m],d[m]);
    }
}

u[0]={0,0};
d[0]={0,0};

memset(mem,-1,sizeof mem);

cout<<dp();

return 0;
}
