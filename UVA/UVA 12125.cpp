/*
   we can use max flow to solve that problem  , ice will be the nodes and the jump will be the edges.
   there will be edge between two ices if the distance between them <= D  .
   we will split each node to two nodes with capacity  between them = number of jumps , that ice can used.
   and each time will use node as a sink and connect the other nodes with a dummy source with
   capacity  between them = number of penguins in that node.
   and if the max flow = sum of penguins in all nodes expect the sink they can meet in that ice .
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
const int N=2800000,M=20000000;

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

int src,snk;
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

double dis(int a,int b,int c,int d)
{
    return sqrt(abs(a-c)*abs(a-c)+abs(b-d)*abs(b-d));
}

double d;
int t,x[110],y[110],a[110],b[110];
 main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
//printf("%s, ",name[k[i]].c_str());  printf of string
input;
cin>>t;
while(t--)
{
    cin>>n>>d;
    for(int i=0;i<n;i++)
        cin>>x[i]>>y[i]>>a[i]>>b[i];

    int ck=1,m=n;
    src=n*2,n=src+1;
    for(int i=0;i<m;i++)
    {
        snk=i;
        int sum=0;
        init();
        for(int j=0;j<m;j++)
        {
            if(j!=i)
            {
             addAugEdge(src,j,a[j]);
             sum+=a[j];
            }
            addAugEdge(j,j+m,b[j]);
        }
        for(int u=0;u<m;u++)
        for(int v=0;v<m;v++)
        {
            if(u==v)continue;
            if(dis(x[u],y[u],x[v],y[v])<=d)
            {
                addAugEdge(u+m,v,oo);
                addAugEdge(v+m,u,oo);
            }
        }
        int ans=MaxFlow();
        if(ans==sum)
        {
            if(ck)cout<<i;
            else cout<<" "<<i;
            ck=0;
        }
    }
    if(ck)cout<<"-1";
    cout<<endl;
}

return 0;
}
