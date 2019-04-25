/*
   we can use  max flow to match the events with number of days <= 200 , and it is easy to find
   days to another events because number of events <= 100
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
const int N=10001000,M=101000;


int head[N],nxt[M],to[M],cap[M],flow[M];
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
			flow[e]++;
			flow[e^1]--;
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
int m,l[110],r[110],ck[N],ans[N];
map<int,int>tak;
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

cin>>m;
n=103+1e7;
init();
src=0,snk=n-1;
forr(i,1,m)
{
    cin>>l[i]>>r[i];
    if(r[i]-l[i]<=200)
    {
        addAugEdge(src,i,1);
        forr(j,l[i],r[i])
        {
            addAugEdge(i,m+j,1);
            if(ck[j]==0)
            {
                ck[j]=1;
                addAugEdge(m+j,snk,1);
            }
        }
    }
}

MaxFlow();

for(int e=0;e<ne;e++)
{
    int f=to[1^e];
    int t=to[e];
    if(f!=src&&t!=snk&&flow[e])
    {
        ans[f]=t-m;
        tak[t-m]=1;
    }
}


for(int i=1;i<=m;i++)
{
    if(r[i]-l[i]>200)
    {
        forr(j,l[i],l[i]+200)
        {
            if(tak.count(j)==0)
            {
                tak[j]=1;
                ans[i]=j;
                break;
            }
        }
    }
}

forr(i,1,m)
cout<<ans[i]<<" ";

return 0;
}
