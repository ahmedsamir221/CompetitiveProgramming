
//   normal dijkstra 

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
int x[8]={-1,-1,0,1,1,1,0,-1};
int y[8]={0,1,1,1,0,-1,-1,-1};
const int N=10001000,M=101000;
int n,m,r1,r2,c1,c2,dis[1005][1005];
char a[1005][1005];
bool valid(int i,int j)
{
    if(i<1||i>n||j<1||j>m)return 0;
    return 1;
}
void dk()
{
    memset(dis,'?',sizeof dis);
    priority_queue<pair<int,pair<int,int>>> q;
    q.push({0,{r1,c1}});
    dis[r1][c1]=0;
    while(q.size())
    {
        int d=-q.top().F;
        int i=q.top().S.F;
        int j=q.top().S.S;
        q.pop();
        for(int e=0;e<8;e++)
        {
            int u=i+x[e];
            int v=j+y[e];
            if(valid(u,v)&&dis[u][v]>dis[i][j]+(a[i][j]-'0'==e?0:1))
            {
                dis[u][v]=dis[i][j]+(a[i][j]-'0'==e?0:1);
                q.push({-dis[u][v],{u,v}});
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
input;
cin>>n>>m;

forr(i,1,n)
forr(j,1,m)
cin>>a[i][j];

int q;
cin>>q;

while(q--)
{
    cin>>r1>>c1>>r2>>c2;
    dk();
    cout<<dis[r2][c2]<<endl;
}


return 0;
}
