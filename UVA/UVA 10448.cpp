/*
   because the path is unique we will get that path with DFS then use DP to check if we can
   obtain the desired cost
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
int n,m,k,mem[55][100005],cas,vis[55],id;
vector<int>b;
vector<pair<int,int>>a[55];
int getpath(int s,int d,int u)
{
    if(u==d) return 1;
    vis[u]=id;
    for(auto v:a[u])
    {
        if(vis[v.F]==id)continue;
        int x=getpath(s,d,v.F);
        if(x)
        {
            b.push_back(v.S);
            return 1;
        }
    }
    return 0;
}
int dp(int i,int c)
{
    if(c<0)return 1e7;
    if(i==(int)b.size()-1)
    {
        if(c==b[(int)b.size()-1])return 1;
        else return 1e7;
    }
    int&ret=mem[i][c];
    if(~ret)return ret;
    int p1=dp(i+1,c-b[i])+1;
    int p2=dp(i,c-2*b[i])+2;
    return ret=min(p1,p2);
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
int t;
cin>>t;
while(t--)
{
    cin>>n>>m;
    int u,v,c;
    forr(i,1,n)a[i].clear();

    forr(i,1,m)
    {
        cin>>u>>v>>c;
        a[u].push_back({v,c});
        a[v].push_back({u,c});
    }

    if(cas++)cout<<endl;
    int q;
    cin>>q;
    while(q--)
    {
        cin>>u>>v>>c;
        b.clear();
        id++;
        if(u==v||getpath(u,v,u)==0)
        {
            cout<<"No"<<endl;
            continue;
        }
        reverse(b.begin(),b.end());
        memset(mem,-1,sizeof mem);
        int x=dp(0,c);
        if(x<1e7) cout<<"Yes "<<x<<endl;
        else cout<<"No"<<endl;
    }
}



return 0;
}
