/*
  we will represent each planet as a two nodes in graph , i and (i+n)  , make edge between them i -->> (i+n) with capacity = 1 ;
  if there are two connected planets u and v , will make two edges , u+n-->>v  and   v+n-->>u with capacity = 1;
  make dummy source and connect it with nodes 1 and 3
  make node 2 sink
  then if the flow==2 the answer will be "YES";
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


const int N=1000000;

int head[N],nxt[N],to[N],cap[N];
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

int t,m;
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
    cin>>n>>m;
    src=0;
    snk=2;
    int k=n;
    n*=2;
    n++;
    init();

    addAugEdge(src,1,1);
    addAugEdge(src,3,1);

    forr(i,1,k)
    addAugEdge(i,i+k,1);

    int u,v;
    forr(i,1,m)
    {
        cin>>u>>v;
        addAugEdge(u+k,v,1);
        addAugEdge(v+k,u,1);
    }

    if(MaxFlow()==2)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
return 0;
}
