/*
    we need to find the path to the node that will be the end node to us with  max probability .
    that path will be no more than (n-1) edge , so we will use dp  to try all paths .
    if we will end at node x our remaining result to the end of the game will be p[x]=win[x]/(1-Continuous[x])
*/
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
const int N = 2e6 + 9;
int n,a[55][55],win[55],los[55],con[55];
double mem[55][55];
double dp(int u,int cnt)
{
    if(cnt==n)return 0;
    double&ret=mem[u][cnt];
    if(ret==ret)return ret;
    ret=0;
    for(int v=0;v<n;v++)
    {
        if(!a[u][v])continue;
        if(u==v)
        {
            double k=win[u]*1.0/100.0;
            k/=(1.0-con[u]*1.0/100.0);
            ret=max(ret,k);
        }
        else
        {
            double k=win[v]*1.0/100.0;
            k+=(con[v]*1.0/100.0)*dp(v,cnt+1);
            ret=max(ret,k);
        }
    }
    return ret;
}
class GraphWalkWithProbabilities{
public:
    double findprob(vector <string> graph, vector <int> winprob, vector <int> looseprob, int Start)
    {
        n=graph.size();
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)a[i][j]=graph[i][j]-'0';
        for(int i=0;i<n;i++)win[i]=winprob[i],los[i]=looseprob[i],con[i]=100-win[i]-los[i];
        memset(mem,-1,sizeof mem);
        return dp(Start,0);
    }

};
