/*
   we can use max flow and connect the banks with source and the border of grid with sink ,
   split each node to two nodes to prevent use the node more than one
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
const int N=100000,M=100000;

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

int num[55][55],ck[55][55];
 main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
//printf("%s, ",name[k[i]].c_str());  printf of string
//priority_queue<ll,vector<ll>,greater<ll>>y;
input;
int t,r,c,q;
cin>>t;
while(t--)
{
    cin>>r>>c>>q;
    memset(ck,0,sizeof ck);
    forr(i,1,q)
    {
        cin>>x>>y;
        ck[x][y]=1;
    }
    src=0,snk=r*c*2+1;
    n=snk+1;
    init();
    int k=0;
    forr(i,1,r)
    forr(j,1,c)
    num[i][j]=++k;

    forr(i,1,r)
    forr(j,1,c)
    {
        addAugEdge(num[i][j],num[i][j]+r*c,1);

        if(ck[i][j])
            addAugEdge(src,num[i][j],1);
        if(i==1||j==1||i==r||j==c)
            addAugEdge(num[i][j]+r*c,snk,1);

        if(i>1)addAugEdge(num[i][j]+r*c,num[i-1][j],1);
        if(i<r)addAugEdge(num[i][j]+r*c,num[i+1][j],1);
        if(j>1)addAugEdge(num[i][j]+r*c,num[i][j-1],1);
        if(j<c)addAugEdge(num[i][j]+r*c,num[i][j+1],1);
    }

    if(MaxFlow()==q)cout<<"possible"<<endl;
    else cout<<"not possible"<<endl;

}
return 0;
}
