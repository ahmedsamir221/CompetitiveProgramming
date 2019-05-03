//http://codeforces.com/blog/entry/46662
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

int n,m,q,x[100005],y[100005],t[100005],ans,sum[1005],ck[1005],a[1005][1005],k[100005],d[100005];
vector<int>st[100005];

void add(int i,int j,int c,int s)
{
    if(!d[c]&&s)return;
    ans-=sum[i];
    if(!ck[i])
    {
        if(a[i][j]==0)a[i][j]=1,sum[i]++,d[c]=1;
    }
    else
    {
        if(a[i][j]==1)a[i][j]=0,sum[i]++,d[c]=1;
    }
    ans+=sum[i];
}

void remov(int i,int j,int c,int s)
{
    if(!d[c]&&s)return;
    ans-=sum[i];
    if(!ck[i])
    {
        if(a[i][j]==1)a[i][j]=0,sum[i]--,d[c]=1;
    }
    else
    {
        if(a[i][j]==0)a[i][j]=1,sum[i]--,d[c]=1;
    }
    ans+=sum[i];
}

void inver(int i)
{
    ans-=sum[i];
    ck[i]=!ck[i];
    sum[i]=m-sum[i];
    ans+=sum[i];
}

void dfs(int u,int p)
{
    if(u>0)
    {
        if(t[u]==1)add(x[u],y[u],u,0),k[u]=ans;
        else if(t[u]==2)remov(x[u],y[u],u,0),k[u]=ans;
        else if(t[u]==3)inver(x[u]),k[u]=ans;
        else k[u]=k[p];
    }
    for(auto v:st[u])
        dfs(v,u);

    if(u>0)
    {
        if(t[u]==1)remov(x[u],y[u],u,1);
        else if(t[u]==2)add(x[u],y[u],u,1);
        else if(t[u]==3)inver(x[u]);
       // cout<<u<<"   "<<ans<<endl;
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
cin>>n>>m>>q;

forr(i,1,q)
{
    cin>>t[i]>>x[i];
    if(t[i]<3)cin>>y[i];

    if(t[i]==4)
        st[x[i]].push_back(i);
    else
        st[i-1].push_back(i);
}
dfs(0,0);


forr(i,1,q)cout<<k[i]<<endl;
return 0;
}
