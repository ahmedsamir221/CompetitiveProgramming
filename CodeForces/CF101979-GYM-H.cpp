/*
   max number of bridges in graph of N nodes is (N-1) , so if M > 2*(N-1) there will not be a solution .
   if M <= 2*(N-1)  will get check the number of bridges
*/
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
//template<typename T>T gcd(T x, T y) { if(y == 0)return x; else return gcd(y, x%y); }
//typedef bitset<30> mask;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//#define var(x) ((x)<<1)
//#define nvar(x) ((x)^1)
const int N=500005,M=1000000;
const double EPS= 1e-8;

int n,m,vis[N],isArt[N],lo[N],cur,root,ckroot;
int nxt[M],to[M],head[N],ne;
vector<pair<int,int>>brd;

void add_edge(int f,int t)
{
    to[ne]=t;
    nxt[ne]=head[f];
    head[f]=ne++;
}
void dfs(int u,int p)
{
    vis[u]=lo[u]=cur++;
    for(int e=head[u];~e;e=nxt[e])
    {
        int v=to[e];
        if(e==p)continue;
        if(vis[v]==-1)
        {
            dfs(v,e^1);
            lo[u]=min(lo[u],lo[v]);
            if(lo[v]>vis[u])brd.push_back({min(u,v),max(u,v)});
        }
        else lo[u]=min(lo[u],vis[v]);
    }
}

vector<pair<int,int>> go()
{
    memset(vis,-1,(n+1)*sizeof vis[0]);
    brd.clear();
    cur=0;
    forr(i,0,n-1) if(vis[i]==-1) dfs(i,-1);
    sort(brd.begin(),brd.end());
    return brd;
}
 int main()
{

input;
cin>>n>>m;
if(m>(n-1)*2)
{
    cout<<"! No"<<endl;
    fflush (stdout);
    return 0;
}
memset(head,-1,(n+1)*sizeof head[0]);
int c=n*3,u=1,v;
while(c--&&u<=n)
{
    cout<<"? "<<u<<endl;
    fflush (stdout);
    cin>>v;
    if(v==-1)
    {
        u++;
        continue;
    }
    add_edge(u,v);
    add_edge(v,u);
}
vector<pair<int,int>>ans=go();
if((int)ans.size()*2>=m)
{
    cout<<"! Yes"<<endl;
    fflush (stdout);
    m++;
    m/=2;
    for(auto p:ans)
    {
        cout<<p.F<<" "<<p.S<<endl;
        fflush (stdout);
        m--;
        if(!m)break;
    }
}
else
{
    cout<<"! No"<<endl;
    fflush (stdout);
}
return 0;
}
