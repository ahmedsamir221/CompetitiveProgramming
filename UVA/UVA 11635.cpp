/*
    if we have a graph of just hotels we can use BFS to minimize number of hotel from start to end .
    so we will get all the distances from hotels and each others using dijkstra then use BFS .
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


int n,m,h,s[10005],d[10005],vis[10005],vid,cnt;
vector<pair<int,int>>a[10005],b[10005];
int dis[104][10005],k[10005];

void dk(int x)
{
    k[x]=++cnt;
    priority_queue<pair<int,int>>q;
    dis[cnt][x]=0;
    q.push({0,x});
    while(q.size())
    {
        int d=-q.top().F;
        int u=q.top().S;
        q.pop();
        if(d>dis[cnt][u])continue;

        for(auto v:a[u])
        {
            if(dis[cnt][v.F]>d+v.S)
            {
               dis[cnt][v.F]=d+v.S;
               q.push({-dis[cnt][v.F],v.F});
            }
        }
    }
}

int bfs()
{
    queue<int>q;
    vid++;
    vis[1]=vid;
    d[1]=0;
    q.push(1);
    while(q.size())
    {
        int u=q.front();
        q.pop();
        if(u==n)return (d[u]-1);
        for(auto v:b[u])
        {
            if(v.S<=600&&vis[v.F]!=vid)
            {
               d[v.F]=d[u]+1;
               vis[v.F]=vid;
               q.push(v.F);
            }
        }
    }
    return -1;
}

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
while(scanf("%d",&n),n)
{
    cnt=0;
    scanf("%d",&h);
    forr(i,1,h)scanf("%d",&s[i]);
    int u,v,w;
    scanf("%d",&m);
    forr(i,1,m)
    {
        scanf("%d%d%d",&u,&v,&w);
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    memset(dis,'?',sizeof dis);

    dk(1);
    forr(i,1,h)
        dk(s[i]);

    forr(i,1,h)
      b[1].push_back({s[i],dis[k[1]][s[i]]});

    b[1].push_back({n,dis[k[1]][n]});

    forr(i,1,h)
    {
        int u=s[i];
        forr(j,i+1,h)
        {
            int v=s[j];
            b[u].push_back({v,dis[k[u]][v]});
            b[v].push_back({u,dis[k[v]][u]});
        }
        b[s[i]].push_back({n,dis[k[u]][n]});
    }
    printf("%d\n",bfs());


    forr(i,1,n)
    a[i].clear(),b[i].clear();

}
return 0;
}
