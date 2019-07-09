//https://codeforces.com/blog/entry/53461
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
const int N=100005,M=100000;
const double EPS= 1e-8;
int n,q,l[N],p[N][20],dis[N];
vector<int>a[N];
void dfs(int u,int P)
{
    for(auto v:a[u])
    {
        if(v==P)continue;
        else {
            dis[v]=dis[u]+1;
            l[v]=l[u]+1;
            p[v][0]=u;
            dfs(v,u);
        }
    }
}
void pre()
{
    forr(j,1,19)
      forr(i,1,n)
         if(p[i][j-1]!=-1)p[i][j]=p[p[i][j-1]][j-1];
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
int distanc(int x,int y)
{
    int LCA=lca(x,y);
    return dis[x]-dis[LCA]+dis[y]-dis[LCA];
}
int get(int s,int t,int f)
{
    int LCA1=lca(s,t);
    int LCA2=lca(s,f);
    int LCA3=lca(t,f);
    int LCA4=lca(LCA1,f);
    if(LCA4!=LCA1) return distanc(LCA1,f);
    else return min(distanc(LCA3,f),distanc(LCA2,f));
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
cin>>n>>q;
int v;
forr(i,2,n)
{
    cin>>v;
    a[i].push_back(v);
    a[v].push_back(i);
}
memset(p,-1,sizeof p);
dfs(1,-1);
pre();
int s,t,f;
while(q--){
    cin>>s>>t>>f;
    int ans=0;
    ans=max(ans,get(s,t,f));
    ans=max(ans,get(s,f,t));
    ans=max(ans,get(t,f,s));
    cout<<ans+1<<endl;
}

return 0;
}
