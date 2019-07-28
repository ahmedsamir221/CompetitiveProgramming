/*
   we need to get the borders of each character then put an edge between that character and any other character
   within it's borders .

   then check the lexicographical topological sort of our new graph .

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
int a[200][200],d[200],ck[200];
string ans;
void topo()
{
    for(int i=0;i<130;i++)
        for(int j=0;j<130;j++)
          if(a[i][j])d[j]++;
    priority_queue<int,vector<int>,greater<int>>q;
    for(int i=0;i<130;i++)
        if(((i>='0'&&i<='9')||(i>='a'&&i<='z')||(i>='A'&&i<='Z'))&&d[i]==0&&ck[i])q.push(i);
    while(q.size())
    {
        int u=q.top();
        ans.push_back((char)u);
        q.pop();
        for(int v=0;v<130;v++)
        {
            if(a[u][v])
            {
                d[v]--;
                if(!d[v])q.push(v);
            }
        }
    }
   for(int i=0;i<130;i++)
        if(d[i])
        {
            ans="ERROR!";
            break;
        }

}
class TopView{
public:

    string findOrder(vector <string> grid){
        int n=grid.size();
        int m=grid[0].size();
        for(char x='0';x<='9';x++)
        {
          int l=1e7,r=-1e7,u=1e7,d=-1e7;
          for(int i=0;i<n;i++)
          {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==x)
                {
                    ck[(int)x]=1;
                    u=min(u,i);
                    d=max(d,i);
                    l=min(l,j);
                    r=max(r,j);
                }
            }
          }
          if(l!=1e7)
          for(int i=u;i<=d;i++)
          {
            for(int j=l;j<=r;j++)
            {
                if(grid[i][j]=='.')return "ERROR!";
                if(grid[i][j]!=x)
                {
                  a[(int)x][(int)grid[i][j]]=1;
                }
            }
          }
        }
        /////////////////////////////
        for(char x='a';x<='z';x++)
        {
          int l=1e7,r=-1e7,u=1e7,d=-1e7;
          for(int i=0;i<n;i++)
          {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==x)
                {
                    ck[(int)x]=1;
                    u=min(u,i);
                    d=max(d,i);
                    l=min(l,j);
                    r=max(r,j);
                }
            }
          }
          if(l!=1e7)
          for(int i=u;i<=d;i++)
          {
            for(int j=l;j<=r;j++)
            {
                if(grid[i][j]=='.')return "ERROR!";
                if(grid[i][j]!=x)
                {
                  a[(int)x][(int)grid[i][j]]=1;
                }
            }
          }
        }
        /////////////////////////////
        for(char x='A';x<='Z';x++)
        {
          int l=1e7,r=-1e7,u=1e7,d=-1e7;
          for(int i=0;i<n;i++)
          {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==x)
                {
                    ck[(int)x]=1;
                    u=min(u,i);
                    d=max(d,i);
                    l=min(l,j);
                    r=max(r,j);
                }
            }
          }
          if(l!=1e7)
          for(int i=u;i<=d;i++)
          {
            for(int j=l;j<=r;j++)
            {
                if(grid[i][j]=='.')return "ERROR!";
                if(grid[i][j]!=x)
                {
                  a[(int)x][(int)grid[i][j]]=1;
                }
            }
          }
        }
        topo();
        return ans;
    }
};
