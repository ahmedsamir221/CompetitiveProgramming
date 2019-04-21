/*
    first we will use the second question by use any node from the second set and after get the answer we will get the nearest
    node to that node from the first set , if there are a common nodes that node must be one of them because there are only one 
    path between any two nodes in tree.
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
const int N=2800000,M=20000000;

int t,n,k,x,y,vis[1005];
map<int,int>a,b;
vector<int>adj[1005];
void init()
{
    forr(i,1,n)
    {
        vis[i]=0;
        adj[i].clear();
    }
    y=0;
    a.clear();
    b.clear();
}
void dfs(int u)
{
    vis[u]=1;
    if(a.count(u))
    {
        y=u;
        return ;
    }
    for(auto v:adj[u])
    {
        if(!vis[v])
            dfs(v);
        if(y)return;
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
cin>>t;
while(t--)
{
    cin>>n;
    init();
    int u,v;
    forr(i,1,n-1)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin>>k;
    forr(i,1,k)
    {
        cin>>x;
        a[x]=1;
    }
    cin>>k;
    forr(i,1,k)
    {
        cin>>x;
        b[x]=1;
    }
    cout<<"B "<<x<<endl;
    cout.flush();
    cin>>x;
    dfs(x);
    cout<<"A "<<y<<endl;
    cout.flush();
    cin>>x;
    cout<<"C ";
    if(b.count(x))
        cout<<y<<endl;
    else
        cout<<"-1"<<endl;
    cout.flush();
}
return 0;
}
