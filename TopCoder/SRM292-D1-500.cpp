/*
   we will do bfs from all name that have no boss  and count number of bosses 
   if there is any element we did not visit it  , there will not be answer
   else will be the count of bfs
*/
#include <iostream>
#include<vector>
#include<algorithm>
//#include <cmath>
//#include <complex>
#include<queue>
#include<map>
#include <string>
#include<bits/stdc++.h>
//#define pi 3.141592654
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
vector<int>a[55];
int c,vis[55];

void bfs(int u)
{
   queue<int>q;
   q.push(u);
   vis[u]=1;
   while(q.size())
   {
       u=q.front();
       q.pop();
       int ck=0;
       for(auto v:a[u])
       {
           if(!vis[v])
           {
               ck++;
               vis[v]=1;
               q.push(v);
           }
       }
       if(ck)c++;
   }
}
class BobTrouble{
public:
    int minSupers(vector <string> name, vector <string> bossName)
    {

       for(int i=0;i<(int)name.size();i++)
       {
           if(bossName[i]=="*")continue;
           for(int j=0;j<(int)name.size();j++)
           {
               if(i==j)continue;
               if(name[j]==bossName[i])a[j].push_back(i);
           }
       }

       for(int i=0;i<(int)name.size();i++)
           if(bossName[i]=="*")bfs(i);
       for(int i=0;i<(int)name.size();i++)
        if(vis[i]==0)return -1;
       return c;
    }
};
