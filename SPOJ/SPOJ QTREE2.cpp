/*
   we will root the tree from node 1 and calculate the distance to each node .
   we need to function
     1 --> the KTH ancestor of each node
     2 --> LCA between any two nodes
   to get DIST query  = distance from a to LCA +   distance from b to LCA
   to get KTH query  we need to know the size of path from a to b and get the answer from the KTH ancestor .

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

/*
#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep ,cos
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel , sin
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))
*/

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
const int N=100000,M=100000;
const double EPS= 1e-8;
int n,dis[10005],l[10005],p[10005][20];
vector<pair<int,int>>a[10005];
void dfs(int u,int P)
{
    for(auto v:a[u])
    {
        if(v.F==P)continue;
        else {
            dis[v.F]=dis[u]+v.S;
            l[v.F]=l[u]+1;
            p[v.F][0]=u;
            dfs(v.F,u);
        }
    }
}
void pre()
{
    forr(j,1,19)
      forr(i,1,n)
         if(p[i][j-1]!=-1)p[i][j]=p[p[i][j-1]][j-1];
}
int kth(int u,int k)
{
    for(int j=19;j>=0;j--)
        if(k>=(1<<j))u=p[u][j],k-=(1<<j);
    return u;
}
int lca(int u,int v)
{
    int ans;
    if(l[u]<l[v])swap(u,v);
    for(int j=19;j>=0;j--)
        if(p[u][j]!=-1&&l[p[u][j]]>=l[v])u=p[u][j];
    if(u==v)return u;
    for(int j=19;j>=0;j--)
        if(p[u][j]!=p[v][j])u=p[u][j],v=p[v][j];
    return p[u][0];
}
 int main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("262144.in","r",stdin);
//freopen("262144.out","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
//printf("%s, ",name[k[i]].c_str());  printf of string
//priority_queue<ll,vector<ll>,greater<ll>>y;
input;
int t;
cin>>t;
while(t--)
{
    cin>>n;
    int u,v,w;
    forr(i,1,n)a[i].clear();
    forr(i,1,n-1)
    {
        cin>>u>>v>>w;
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    memset(p,-1,sizeof p);
    p[1][0]=-1;
    dis[1]=0;
    l[1]=0;
    dfs(1,-1);
    pre();
    string s;
    int k;
    while(1)
    {
        cin>>s;
        if(s=="DONE")break;
        else if(s=="DIST"){
            cin>>u>>v;
            int LCA=lca(u,v);
            cout<<dis[u]-dis[LCA]+dis[v]-dis[LCA]<<endl;
        }
        else{
            cin>>u>>v>>k;
            k--;
            int LCA=lca(u,v);
            int path=l[u]-l[LCA]+l[v]-l[LCA];
            if(k>l[u]-l[LCA])cout<<kth(v,path-k)<<endl;
            else cout<<kth(u,k)<<endl;
        }
    }
    cout<<endl;
}

return 0;
}
