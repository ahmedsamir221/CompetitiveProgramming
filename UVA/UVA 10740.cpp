//https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/UVA/UVA_10740.txt
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

int n,m,s,e,k,vis[110],cnt;
vector<pair<int,int>>a[110];

int djk(int u,ll dis)
{
    priority_queue<pair<int,int>>q;
    q.push({0,u});
    memset(vis,0,sizeof vis);
    cnt=0;
    while(q.size())
    {
    u=q.top().S;
    dis=-q.top().F;
    q.pop();
    vis[u]++;
    if(u==e)
    {
        cnt++;
        if(cnt==k)return dis;
    }
    for(auto v:a[u])
        if(vis[v.F]<k)
            q.push({-(dis+(ll)v.S),v.F});
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
input;

while(cin>>n>>m,n||m)
{
    cin>>s>>e>>k;
    forr(i,1,n)a[i].clear();
    int u,v,d;
    forr(i,1,m)
    {
        cin>>u>>v>>d;
        a[u].push_back({v,d});
    }
    cout<<djk(s,0)<<endl;
}
return 0;
}
