/*
  because the degree of node at most 20 so we will back track from each node and 
  get all possible graph with size = S and keep in mind the repetition of graphs  
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
int n,m,s,t,id,a[105][105],ck[105];
vector<int>adj[105],e;
ll ans;
void bk(int i,int j)
{
    if(e.size()==s)
    {
      ans++;
      return ;
    }
    if(j==adj[i].size())return;

    bk(i,j+1);
    int h=1;
    for(auto p:e)
    {
        if(a[p][adj[i][j]]!=id)
        {
            h=0;
            break;
        }
    }
    if(h)
    {
            e.push_back(adj[i][j]);
            bk(i,j+1);
            e.pop_back();
    }

}
int main()
{

//cout<<Pow((ll)1000000,(ll)110);a
//freopen("tour.in","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
cin>>t;
while(t--)
{
    cin>>n>>m>>s;
    id++;
    memset(ck,0,sizeof ck);
    int x,y;
    forr(i,1,n)adj[i].clear();
    forr(i,1,m)
    {
        cin>>x>>y;
        a[x][y]=id;
        a[y][x]=id;
        if(x<=y)
        adj[x].push_back(y);
        else
        adj[y].push_back(x);
        ck[x]++;
        ck[y]++;
    }
    forr(i,1,n)sort(adj[i].begin(),adj[i].end());
    ans=0;
    forr(i,1,n)
    {
        if(ck[i]>=s-1)
        {
            e.clear();
            e.push_back(i);
            bk(i,0);
        }
    }
    cout<<ans<<endl;
}
return 0;
}
