/*
  we will use dp , our state will be start and end ,then each time check if we can color our segment with
  one color or split it and minimize the answer

*/
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
int n,mem[55][55],sz,c,cc;
int dp(int l,int r,string&a)
{
   if(r-l+1<sz)return 1e8;
   int&ret=mem[l][r];
   if(~ret)return ret;
   ret=1e8;
   set<char>s;
   forr(i,l,r)
   {
       if(a[i]!='*') s.insert(a[i]);
       if(i!=r) ret=min(ret,dp(l,i,a)+dp(i+1,r,a));
   }
   if(s.size()<=1)
      ret=min(ret,(r-l+sz)/sz*cc);
   return ret;
}

class Stamp{
public:

   int getMinimumCost(string desiredColor, int stampCost, int pushCost)
   {
       n=desiredColor.size();
       c=stampCost;
       cc=pushCost;
       int ans=1e9;
       forr(i,1,n)
       {
         sz=i;
         memset(mem,-1,sizeof mem);
         ans=min(ans,dp(0,n-1,desiredColor)+c*i);
       }
       return ans;
   }
};
