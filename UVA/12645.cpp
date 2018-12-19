/*
  the answer is number of component that has at least of node that can reach to all other nodes
  except the component of node zero
  so we can do that by DFS by sorting nodes according to its in degree
  and count number of component 
*/
#include<stdio.h>
#include<vector>
#include<algorithm>
#include <iostream>
#include <cmath>
#include <complex>
#include<queue>
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
//const double PI = acos(-1.0);
//const double EPS = 1e-9;
//typedef complex<double> point;
int n,m,vis[1010],ck[1010],ans,u,v,id[1010];
vector<int>a[1010];
void dfs(int s)
{
    vis[s]=1;
    for(auto p:a[s])
        if(vis[p]==0)
             dfs(p);
}

bool com(int i,int j)
{
    if(ck[i]<ck[j])return 1;
    return 0;
}
int main()
{

//cout<<Pow((ll)1000000,(ll)110);a
//freopen("trip.in","r",stdin);
//freopen("trip.out","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
while(cin>>n)
{
    cin>>m;
    forr(i,1,m)
    {
        cin>>u>>v;
        if(v==0)continue;
        ck[v]++;
        a[u].push_back(v);
    }
    forr(i,0,n)id[i]=i;

    sort(id,id+n+1,com);

    ans=-1;
    forr(j,0,n)
    {
        int i=id[j];
        if(vis[i]==0)
        {
            ans++;
            dfs(i);
        }
    }
    cout<<ans<<endl;
    forr(i,0,n)
    {
        a[i].clear();
        vis[i]=0;
        ck[i]=0;
    }
}

return 0;
}
