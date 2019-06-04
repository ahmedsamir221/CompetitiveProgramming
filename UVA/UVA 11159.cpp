/*
    we will connect the source node with all elements in set A , connect the sink node with all elements in set B
    and connect each element in set A with all the multiples of it in set B ;
    the the answer will be the max flow from the source to the sink

*/
#include<queue>
#include<map>
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
//#define var(x) ((x)<<1)
//#define nvar(x) ((x)^1)
const int N=210,M=20500;

int head[N],nxt[M],to[M],cap[M];
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

int a[N],b[N],cas;
 main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
//printf("%s, ",name[k[i]].c_str());  printf of string
//input;
int t,r,c;
scanf("%d",&t);
while(t--)
{
    scanf("%d",&r);
    forr(i,1,r)scanf("%d",&a[i]);

    scanf("%d",&c);
    forr(i,1,c)scanf("%d",&b[i]);

    src=0;
    snk=r+c+1;
    n=snk+1;
    init();

    forr(i,1,r)addAugEdge(src,i,1);

    forr(i,1,c)addAugEdge(i+r,snk,1);


    forr(i,1,r)
        forr(j,1,c)
        {
            if(a[i]==0&&b[j]!=0)continue;
            if((a[i]==0&&b[j]==0)||b[j]%a[i]==0)
                addAugEdge(i,r+j,1);
        }

    printf("Case %d: %d\n",++cas,MaxFlow());

}
return 0;
}
