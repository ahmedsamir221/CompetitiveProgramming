/*
   if we start walking from any node and return back to the same node from two paths or more 
   then the answer is  "Unbounded" , otherwise the answer is "Bounded" .
   we can check that by the max flow if the flow from any node to it self > 1 then  the answer is  "Unbounded" .
    
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

const int N=50000,M=1000000;
const double EPS= 1e-9;

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
		if(flow>1)return flow;
	}while(f);
	return flow;
}

class BigOEasy{
public:
    string isBounded(vector <string> graph){
        int ck=0,m=graph.size();
        for(int u=0;u<m;u++)
        {
            src=u,snk=m,n=snk+1;
            init();
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(graph[i][j]=='Y'){
                    if(i==u)addAugEdge(i,j,1);
                    else if(j==u) addAugEdge(i,snk,oo);
                    else addAugEdge(i,j,oo);
                    }
                }
            }
           // cout<<MaxFlow()<<endl;
            if(MaxFlow()>1)
            {
                ck=1;
                break;
            }
        }
        if(ck)return "Unbounded";
        else return "Bounded";
    }
};
