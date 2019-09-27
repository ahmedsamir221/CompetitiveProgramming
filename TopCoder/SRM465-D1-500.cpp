//https://github.com/Huvok/CompetitiveProgramming/blob/master/Topcoder/SRM465-D1-500.cpp
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


#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);


const double PI  = acos(-1.0);
using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
typedef complex<double> point;

//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
const int N=40007,M=1000000;
const double EPS= 1e-9,eps=-1e9;

int head[N],nxt[N<<1],to[N<<1],cap[N<<1];
int n,ne;
void init()
{
	memset(head,-1,n*sizeof head[0]);
	ne=0;
}

void addEdge(int f, int t, int cp)
{
	to[ne]=t;
	nxt[ne]=head[f];
	cap[ne]=cp;
	head[f]=ne++;
}

void addAugEdge(int u, int v, int cp, int rev=0)
{
	addEdge(u,v,cp);
	addEdge(v,u,rev);
}

int m,x,y,z,src,snk;
int oo=0x3f3f3f3f;
int vis[N],vid;

int dfs(int u, int mn)
{
	if(u==snk)	return mn;
	if(!mn || vis[u]==vid)	return 0;
	vis[u]=vid;
	for(int e=head[u] ; ~e ; e=nxt[e])
	{
		int v=to[e];
		int f=dfs(v,min(mn,cap[e]));
		if(f){
			cap[e]-=f;
			cap[e^1]+=f;
			return f;
		}
	}
	return 0;
}

int MaxFlow()
{
	int flow=0,f;
	do
	{
		++vid;
		f=dfs(src,oo);
		flow+=f;
	}while(f);
	return flow;
}

int dis(int a,int b,int c,int d)
{
    return abs(a-c)*abs(a-c)+abs(b-d)*abs(b-d);
}
class GreenWarfare{
public:
    int minimumEnergyCost(vector <int> canonX, vector <int> canonY, vector <int> baseX, vector <int> baseY, vector <int> plantX, vector <int> plantY, int energySupplyRadius){

        int s1=canonX.size();
        int s2=baseX.size();
        int s3=plantX.size();
        src=0,snk=s2+s3+1,n=snk+1;
        init();
        for(int i=0;i<s2;i++)
        {
            int g=1e9;
            for(int j=0;j<s1;j++)
                g=min(g,dis(baseX[i],baseY[i],canonX[j],canonY[j]));
            addAugEdge(src,i+1,g);
            for(int j=0;j<s3;j++)
            {
                if(dis(baseX[i],baseY[i],plantX[j],plantY[j])<=energySupplyRadius*energySupplyRadius)
                    addAugEdge(i+1,s2+j+1,oo);
            }
        }
        for(int i=0;i<s3;i++)
        {
            int g=1e9;
            for(int j=0;j<s1;j++)
                g=min(g,dis(plantX[i],plantY[i],canonX[j],canonY[j]));
            addAugEdge(s2+i+1,snk,g);
        }
        return MaxFlow();
    }

};
