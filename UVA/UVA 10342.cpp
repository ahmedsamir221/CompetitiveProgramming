//https://ideone.com/x8zpRc
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
int n,m,cas;
vector<pair<int,int>>a[110];
int vis[105],dis[105];
int dk(int s,int e)
{
    memset(vis,0,sizeof vis);
    memset(dis,-1,sizeof dis);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({0,s});
    while(q.size())
    {
        int u=q.top().S;
        int d=q.top().F;
        q.pop();
        if(dis[u]<d) vis[u]++,dis[u]=d;
        if(vis[u]==2&&u==e)return d;
        if(vis[u]>2)continue;
        for(auto v:a[u])
           q.push({d+v.F,v.S});
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
//priority_queue<ll,vector<ll>,greater<ll>>y;
input;
while(cin>>n>>m)
{
    int u,v,w;
    forr(i,0,n-1)a[i].clear();

    forr(i,1,m)
    {
        cin>>u>>v>>w;
        a[u].push_back({w,v});
        a[v].push_back({w,u});
    }
    int q;
    cin>>q;
    cout<<"Set #"<<++cas<<endl;
    while(q--)
    {
        cin>>u>>v;
        int g=dk(u,v);
        if(g!=-1)cout<<g<<endl;
        else cout<<"?"<<endl;
    }
}
return 0;
}
