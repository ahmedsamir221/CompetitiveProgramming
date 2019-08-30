//https://github.com/MohamedNabil97/CompetitiveProgramming/blob/master/TopCoder/SRM447-D1-500.cpp
#include<bits/stdc++.h>
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

//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
const int N=100006,M=1000000;
const double eps= 1e-9,EPS= 1e-9;

int head[N],nxt[N<<1],to[N<<1],cap[N<<1];
int n,m,ne;
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

int src,snk;
int oo=0x3f3f3f3f;
int vis[N],vid;
int dfs(int u, int mn)
{
	if(u==snk)return mn;
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

class PeopleYouMayKnow{
public:
    int maximalScore(vector <string> friends, int person1, int person2){
        m=friends.size();
        n=m*2;
        src=person1;
        snk=person2+m;
        init();
        for(int i=0;i<m;i++)
        {
            if(i==person1||i==person2)addAugEdge(i,i+m,oo);
            else addAugEdge(i,i+m,1);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=i+1;j<m;j++)
            {
                if(friends[i][j]=='Y'&&(i==person1||i==person2||j==person1|j==person2||
                (friends[person1][i]=='Y'&&friends[person2][j]=='Y')||(friends[person1][j]=='Y'&&friends[person2][i]=='Y')))
                    addAugEdge(i+m,j,oo),addAugEdge(j+m,i,oo);
            }
        }
        return MaxFlow();

    }
};
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;

vector<string>v={"NYNN"
,"YNYN"
,"NYNY"
,"NNYN"};

PeopleYouMayKnow kk ;
cout<<kk.maximalScore(v,0,3);
return 0;
}
