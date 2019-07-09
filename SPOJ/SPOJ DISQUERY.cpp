/*
    we need just to get max and min road while we get the LCA between the two nodes .
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
const int N=100005,M=100000;
const double EPS= 1e-8;
int n,l[N],p[N][20],mn[N][20],mx[N][20];
vector<pair<int,int>>a[N];
void dfs(int u,int P)
{
    for(auto v:a[u])
    {
        if(v.F==P)continue;
        else {
            l[v.F]=l[u]+1;
            p[v.F][0]=u;
            mn[v.F][0]=v.S;
            mx[v.F][0]=v.S;
            dfs(v.F,u);
        }
    }
}
void pre()
{
    forr(j,1,19)
      forr(i,1,n)
         if(p[i][j-1]!=-1){
                p[i][j]=p[p[i][j-1]][j-1];
                mn[i][j]=min(mn[i][j-1],mn[p[i][j-1]][j-1]);
                mx[i][j]=max(mx[i][j-1],mx[p[i][j-1]][j-1]);
         }
}
pair<int,int> lca(int u,int v)
{
    pair<int,int> ans={1e9,0};
    if(l[u]<l[v])swap(u,v);
    for(int j=19;j>=0;j--)
        if(p[u][j]!=-1&&l[p[u][j]]>=l[v]){
                ans.F=min(ans.F,mn[u][j]);
                ans.S=max(ans.S,mx[u][j]);
                u=p[u][j];
        }
    if(u==v)return ans;
    for(int j=19;j>=0;j--)
        if(p[u][j]!=p[v][j]){
                ans.F=min(ans.F,mn[u][j]);
                ans.F=min(ans.F,mn[v][j]);
                ans.S=max(ans.S,mx[u][j]);
                ans.S=max(ans.S,mx[v][j]);
                u=p[u][j],v=p[v][j];
        }
    ans.F=min(ans.F,mn[u][0]);
    ans.F=min(ans.F,mn[v][0]);
    ans.S=max(ans.S,mx[u][0]);
    ans.S=max(ans.S,mx[v][0]);
    return ans;
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

cin>>n;
int u,v,w;
forr(i,1,n-1)
{
    cin>>u>>v>>w;
    a[u].push_back({v,w});
    a[v].push_back({u,w});
}
memset(p,-1,sizeof p);
dfs(1,-1);
pre();
int q;
cin>>q;
while(q--){
    cin>>u>>v;
    auto LCA=lca(u,v);
    cout<<LCA.F<<" "<<LCA.S<<endl;
}
return 0;
}
