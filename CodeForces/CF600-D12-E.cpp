//https://codeforces.com/blog/entry/21827
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
const double EPS = 1e-9;
const int N = 1e5 + 9;
int n,c[N],idx[N],sub[N],rep[N];
vector<int>adj[N];
map<int,int>a[N];
ll ans[N];

void get(int u,int p)
{
    int sz=0,i=u;
    sub[u]=1;
    for(auto v:adj[u])
    {
        if(v==p)continue;
        get(v,u);
        sub[u]+=sub[v];
        int j=idx[v];
        if(sub[v]>sz)
        {
            sz=sub[v];
            i=j;
            rep[u]=rep[v];
            ans[u]=ans[v];
            idx[u]=i;
        }
    }
    a[i][c[u]]++;
    if(a[i][c[u]]>rep[u])
    {
        rep[u]=a[i][c[u]];
        ans[u]=c[u];
    }
    else if(a[i][c[u]]==rep[u])ans[u]+=c[u];

    for(auto v:adj[u])
    {
        if(v==p)continue;
        int j=idx[v];
        if(j!=i)
            for(auto k:a[j])
            {
                a[i][k.F]+=k.S;
                if(a[i][k.F]>rep[u])
                {
                    rep[u]=a[i][k.F];
                    ans[u]=k.F;
                }
                else if(a[i][k.F]==rep[u])ans[u]+=k.F;
            }
    }
}
 int main()
{
//freopen("product.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input

        cin>>n;
        forr(i,1,n)cin>>c[i],idx[i]=i;
        int u,v;
        forr(i,1,n-1)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        get(1,-1);
        forr(i,1,n)cout<<ans[i]<<" ";


return 0;
}
