/*
   number of divisor = (x+1) * (y+1) * (z+1) * .......  where x,y,z is the powers of the prime factors 
   so with dp we will try to get that powers
   N!K = product of some number <= N , so we check all prime that <= N  
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
ll n,k,mem[1005][105],m=1e9+9,ck[1005];
ll dp(int i,int j,int s)
{
   if(i==0)return 0;
   if(j==0)
   {
       ll c=0;
       while(i%s==0)c++,i/=s;
       return c;
   }
   ll&ret=mem[i][j];
   if(~ret)return ret;
   return ret=(dp(i,j-1,s)%m+dp(i-1,j,s)%m)%m;
}

class MegaFactorialDiv2{
public:

   int countDivisors(int N, int K)
   {
       n=N,k=K;
       for(int i=2;i<=n;i++)
          if(!ck[i])
           for(int j=i;j<=n;j+=i)ck[j]=i;
       ll ans=1;
       forr(i,2,n)
       {
         if(ck[i]!=i)continue;
         memset(mem,-1,sizeof mem);
         ans=((ans%m)*((dp(n,k,i)+1)%m))%m;
       }
       return (ans+m)%m;
   }
};
