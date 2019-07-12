/*
   we just need to get the articulation points of our graph
*/
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
const int N=20005,M=100000;
const double EPS= 1e-8;

int n,cas,lo[103],vis[103],cur,root,ckroot,isArt[103];
vector<int>a[103];

void dfs(int u,int p)
{
    vis[u]=lo[u]=cur++;
    for(auto v:a[u])
    {
        if(v==p)continue;
        if(vis[v]==-1)
        {
            dfs(v,-1);
            lo[u]=min(lo[u],lo[v]);
            if(u==root)
            {
                if(!ckroot)ckroot=1;
                else isArt[u]=1;
            }
            else if(lo[v]>=vis[u]) isArt[u]=1;
        }
        else lo[u]=min(lo[u],vis[v]);
    }
}
vector<int> go(){
    memset(vis,-1,(n+1)*sizeof vis[0]);
    memset(isArt,0,(n+1)*sizeof isArt[0]);
    cur=0;
    vector<int> ans;
    forr(i,1,n)
    {
      if(vis[i]==-1)
      {
          root=i;
          ckroot=0;
          dfs(i,-1);
      }
      if(isArt[i])ans.push_back(i);
    }
    return ans;
}
 int main()
{

//input;
while(cin>>n,n)
{
    map<int,string>name;
    map<string,int>num;
    string s,f;
    forr(i,1,n)
    {
        cin>>s;
        a[i].clear();
        name[i]=s;
        num[s]=i;
    }
    int r;
    cin>>r;
    forr(i,1,r)
    {
        cin>>s>>f;
        a[num[s]].push_back(num[f]);
        a[num[f]].push_back(num[s]);
    }
    vector<int> e=go();
    vector<string>ans;
    for(auto p:e)ans.push_back(name[p]);
    sort(ans.begin(),ans.end());
    if(cas++)cout<<endl;
    printf("City map #%d: %d camera(s) found\n",cas,(int)ans.size());
    for(auto p:ans)cout<<p<<endl;
}
return 0;
}
