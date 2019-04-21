/*
   first we will use BFS to determine the nearest enemy base from each cell in the grid.
   then use another BSF from the source to get the answer
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
int x[8]={1,0,0,-1,-1,-1,1,1};
int y[8]={0,1,-1,0,-1,1,-1,1};
//#define var(x) ((x)<<1)
//#define nvar(x) ((x)^1)
const int N=2800000,M=20000000;

int n,m,c,t,dis[1003][1003],mn[1003][1003],k[1003][1003],sx,sy,ex,ey;
pair<int,int>a[10005];

bool valid (int i,int j)
{
    if(i<0||i==n||j<0||j==m)return 0;
    else return 1;
}
void fil()
{
    memset(dis,-1,sizeof dis);
    queue<pair<int,int>>q;
    forr(i,1,c)
    {
        q.push(a[i]);
        dis[a[i].F][a[i].S]=0;
    }
    while(q.size())
    {
        int i=q.front().F;
        int j=q.front().S;
        q.pop();
        for(int e=0;e<4;e++)
        {
            int u=i+x[e];
            int v=j+y[e];
            if(valid(u,v)&&dis[u][v]==-1)
            {
                dis[u][v]=dis[i][j]+1;
                q.push({u,v});
            }
        }

    }
}



void get()
{
    memset(k,-1,sizeof k);
    memset(mn,'?',sizeof mn);
    queue<pair<int,int>>q;
    q.push({sx,sy});
    k[sx][sy]=0;
    mn[sx][sy]=dis[sx][sy];
    while(q.size())
    {
        int i=q.front().F;
        int j=q.front().S;
        q.pop();
        for(int e=0;e<4;e++)
        {
            int u=i+x[e];
            int v=j+y[e];
            if(valid(u,v)&&(k[u][v]==-1||(mn[i][j]>mn[u][v]&&dis[u][v]>mn[u][v])))
            {
                k[u][v]=k[i][j]+1;
                mn[u][v]=min(mn[i][j],dis[u][v]);
                q.push({u,v});
            }
        }

    }
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
scanf("%d",&t);
while(t--)
{
    scanf("%d%d%d",&c,&n,&m);
    scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
    forr(i,1,c)
    cin>>a[i].F>>a[i].S;
    fil();
    get();
    cout<<mn[ex][ey]<<" "<<k[ex][ey]<<endl;
}
return 0;
}
