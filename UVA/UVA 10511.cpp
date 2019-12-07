/*
    we can build our graph like this ;
    1--> connect the source node with all clubs with capacity 1.
    2--> connect each club with it's residents with capacities 1.
    3--> connect each resident with it's political party with capacity 1.
    4--> connect each political party with the sink node  with capacity (number of clubs + 1 )/2 - 1 .

    then get the max flow from the source to the sink .
    if it < number of clubs , then there will be no answer .
    else we will get the match between the clubs and the residents .
 */
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
//#include <ext/pb_ds/assoc_container.hpp>

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
const int N = 2e5 + 9;

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

 int main()
{
 //freopen("product.in","r",stdin);
 //input;
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input

      int t,r=0;
      cin>>t;
      cin.ignore();
      string s;
      getline(cin,s);
      while(t--)
      {
            vector<vector<string> >lines;
            while(getline(cin,s))
            {
                if(s.size()==0)break;
                string f;
                vector<string>cur;
                for(int i=0;i<(int)s.size();i++)
                {
                    if(s[i]!=' ')f.push_back(s[i]);
                    if(s[i]==' '||i==(int)s.size()-1)
                    {
                        cur.push_back(f);
                        f.clear();
                    }
                }
                lines.push_back(cur);
            }
            map<string,int>person,club,party;
            map<int,string>revperson,revclub;
            int c=0;
            for(int i=0;i<(int)lines.size();i++)person[lines[i][0]]=++c,revperson[c]=lines[i][0];
            for(int i=0;i<(int)lines.size();i++)
            {
                if(party.count(lines[i][1]))continue;
                party[lines[i][1]]=++c;
            }
            for(int i=0;i<(int)lines.size();i++)
            {
                for(int j=2;j<(int)lines[i].size();j++)
                {
                     if(club.count(lines[i][j]))continue;
                      club[lines[i][j]]=++c;
                      revclub[c]=lines[i][j];
                }
            }
            src=0,snk=++c,n=snk+1;
            init();
            for(int i=0;i<(int)lines.size();i++)
            {
                addAugEdge(person[lines[i][0]],party[lines[i][1]],1);
                for(int j=2;j<(int)lines[i].size();j++)
                {
                     addAugEdge(club[lines[i][j]],person[lines[i][0]],1);
                }
            }
            for(auto p:club)addAugEdge(src,p.S,1);
            int ff=((int)club.size()+1)/2-1;
            for(auto p:party)addAugEdge(p.S,snk,ff);
            if(MaxFlow()<(int)club.size())cout<<"Impossible."<<endl;
            else
            {
                for(int e=0;e<ne;e++)
                {
                    int v=to[e];
                    int u=to[e^1];
                    if(u>(int)person.size()+(int)party.size()&&v<=(int)person.size()&&cap[e]==0)
                    {
                        cout<<revperson[v]<<" "<<revclub[u]<<endl;
                    }
                }
            }
            if(t)cout<<endl;
      }
return 0;
}
