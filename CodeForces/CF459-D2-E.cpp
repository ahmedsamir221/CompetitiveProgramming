/*
   first we need to sort the all edges then updates them one after another .
   we update them according to the adjacent edges then maximize the answer of edge
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


int n,m,c[300030],id[300030],dis[300030],last[300030],mx[300030];
int u[300030],v[300030],w[300030];
vector<pair<int,int>>a[300030];
bool com(int i,int j)
{
    if(w[i]<w[j])return 1;
    return 0;
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
scanf("%d%d",&n,&m);
forr(i,1,m)
{
    scanf("%d%d%d",&u[i],&v[i],&w[i]);
    a[v[i]].push_back({w[i],i});
    dis[i]=1;
    id[i]=i;
}
sort(id+1,id+m+1,com);

forr(i,1,n)
sort(a[i].begin(),a[i].end());

forr(j,1,m)
{
    int i=id[j];
    for(int e=last[u[i]];e<a[u[i]].size();e++)
    {
        if(a[u[i]][e].F>=w[i])break;

        last[u[i]]=e;
        mx[u[i]]=max(mx[u[i]],dis[a[u[i]][e].S]);
    }
    dis[i]=max(dis[i],mx[u[i]]+1);
}

cout<<*max_element(dis+1,dis+m+1);
return 0;
}
