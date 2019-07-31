/*
    if there are more than one toposort the answer is -1 ;
    otherwise the answer is the  edge we used to add the last element in toposort  ;
*/
#pragma GCC optimize("O3")
#include<queue>
#include <cmath>
#include <complex>
#include<map>
#include <string>
#include<iostream>
#include<bits/stdc++.h>


#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);


using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
typedef complex<double> point;
//template<typename T>T gcd(T x, T y) { if(y == 0)return x; else return gcd(y, x%y); }
//typedef bitset<30> mask;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//#define var(x) ((x)<<1)
//#define nvar(x) ((x)^1)
const int N=500005,M=1000000;
const double EPS= 1e-9;

int n,m,d[N],x[N],y[N],k[N];
vector<int>a[N];
void bfs()
{
    queue<int>q;
    forr(i,1,n)if(!d[i])q.push(i);
    while(q.size())
    {
        if(q.size()>1)
        {
            cout<<"-1";
            exit(0);
        }
        int u=q.front();
        q.pop();
        for(auto v:a[u])
        {
            d[v]--;
            if(!d[v])q.push(v),k[u]=v;
        }
    }
}



 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;


cin>>n>>m;
int u,v;
forr(i,1,m)
{
    cin>>x[i]>>y[i];
    a[x[i]].push_back(y[i]);
    d[y[i]]++;
}
bfs();
int c=n;
forr(i,1,m)
{
    if(k[x[i]]==y[i])c--;
    if(c==1)
    {
        cout<<i;
        return 0;
    }
}

return 0;
}
