/*
   we will use dijkstra two times from the start and from the end.
   then check each edge , if the distance from start + from the end + the cost of edge <= P  will maximize the answer .
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

int n,m,s,e,p,u[100004],v[100004],c[100004],disa[10004],disb[10004];
vector<pair<int,int>>a[10004],b[10004];
void init()
{
    forr(i,1,n)
    a[i].clear(),b[i].clear();
}

void dks()
{
    priority_queue<pair<int,int>>q;
    memset(disa,'?',(n+1)*sizeof disa[0]);
    q.push({0,s});
    disa[s]=0;
    while(q.size())
    {
        auto u=q.top();
        q.pop();
        if(disa[u.S]!=-u.F)continue;
        for(auto v:a[u.S])
        {
            if(disa[v.F]>disa[u.S]+v.S)
            {
                disa[v.F]=disa[u.S]+v.S;
                q.push({-disa[v.F],v.F});
            }
        }
    }
}

void dke()
{
    priority_queue<pair<int,int>>q;
    memset(disb,'?',(n+1)*sizeof disb[0]);
    q.push({0,e});
    disb[e]=0;
    while(q.size())
    {
        auto u=q.top();
        q.pop();
        if(disb[u.S]!=-u.F)continue;
        for(auto v:b[u.S])
        {
            if(disb[v.F]>disb[u.S]+v.S)
            {
                disb[v.F]=disb[u.S]+v.S;
                q.push({-disb[v.F],v.F});
            }
        }
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
//input;
int t;
scanf("%d",&t);
while(t--)
{
    scanf("%d%d%d%d%d",&n,&m,&s,&e,&p);
    init();
    forr(i,1,m)
    {
        scanf("%d%d%d",&u[i],&v[i],&c[i]);
        a[u[i]].push_back({v[i],c[i]});
        b[v[i]].push_back({u[i],c[i]});
    }
    dks();
    dke();
    int ans=-1;
    forr(i,1,m)
        if(disa[u[i]]+disb[v[i]]+c[i]<=p&&c[i]>ans)ans=c[i];
    printf("%d\n",ans);
}
return 0;
}
