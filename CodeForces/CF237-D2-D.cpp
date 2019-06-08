//http://codeforces.com/blog/entry/5648
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
const int N=210,M=20500;

int n,vis[100010],c,num[100010];
vector<int>a[100010];
vector<pair<int,int>>k,t;
void dfs(int u)
{
    vis[u]=1;
    vector<int>e;
    if(u!=1) e.push_back(num[u]);
    for(auto v:a[u])
    {
        if(!vis[v])
        {
            num[v]=++c;
            k.push_back({u,v});
            e.push_back(c);
            dfs(v);
        }
    }
    for(int i=0;i<e.size()-1;i++)
    t.push_back({e[i],e[i+1]});
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

cin>>n;
int u,v;
forr(i,1,n-1)
{
    cin>>u>>v;
    a[u].push_back(v);
    a[v].push_back(u);
}
dfs(1);
cout<<n-1<<endl;
for(auto p:k)cout<<"2 "<<p.F<<" "<<p.S<<endl;
for(auto p:t)cout<<p.F<<" "<<p.S<<endl;
return 0;
}
