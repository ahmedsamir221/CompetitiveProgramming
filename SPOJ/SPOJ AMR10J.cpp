//https://stackoverflow.com/questions/55681636/how-to-count-how-many-valid-colourings-in-a-graph
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);

const double PI  = acos(-1.0);
using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
typedef complex<double> point;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
const int N = 2e5 + 9;
vector<int>a[109];
int vis[109],dis[109],c,lc;
ll ans=1,mod=1e9+7,k;
void dfs(int u,int p)
{
    vis[u]=1;
    c++;
    for(int i=0;i<a[u].size();i++)
    {
        int v=a[u][i];
        if(v==p)continue;
        if(vis[v]==1)lc=max(dis[u]-dis[v]+1,lc);
        if(vis[v])continue;
        dis[v]=dis[u]+1;
        dfs(v,u);
    }
    vis[u]=2;
}
/*
void get(int t,int nc)
{
    ll total=0;
    for(int i=nc;i>2;i-=2)
    {
        ll cur=1;
        cur=(1LL*cur*k)%mod;
        cur=(1LL*cur*(k-2))%mod;
        for(int j=0;j<i-2;j++)cur=(1LL*cur*(k-1))%mod;
        total=(total+cur)%mod;
    }
    if(nc%2==0)
    {
        ll cur=1;
        cur=(1LL*cur*k)%mod;
        cur=(1LL*cur*(k-1))%mod;
        total=(total+cur)%mod;
    }
    ans=(ans*total)%mod;
    for(int i=0;i<t-nc;i++)ans=(1LL*ans*(k-1))%mod;
}
*/
void get(int t,int nc)
{
    ll cur=1;
    for(int i=0;i<nc;i++)cur=(cur*(k-1))%mod;

    if(nc%2)cur=(cur-(k-1))%mod;
    else cur=(cur+(k-1))%mod;

    cur=(cur+mod)%mod;
    ans=(ans*cur)%mod;
    for(int i=0;i<t-nc;i++)ans=(ans*(k-1))%mod;
}

 int main()
{
//freopen("product.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
//input
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,x;
        scanf("%d %lld",&n,&k);
        for(int i=0;i<n;i++)a[i].clear();
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            a[i].push_back(x);
            a[x].push_back(i);
        }
        memset(vis,0,sizeof vis);
        memset(dis,0,sizeof dis);
        ans=1;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                c=0,lc=0;
                dfs(i,-1);
                if(lc==0)lc=2;
                get(c,lc);
            }
        }
        printf("%lld\n",(ans+mod)%mod);
    }

return 0;
}
