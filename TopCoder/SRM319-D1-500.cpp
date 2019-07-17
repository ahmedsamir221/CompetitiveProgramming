/*
     the parent of node with value  x is node with value x/2 .
     so we can use dp to count the number of trees we can form starting from node with value 1 .
     to avoid memory limit we can memorize in map instead of array . 
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
const int N=500005,M=1000000;
const double EPS= 1e-8;

ll n,a[30];
map<int,ll>mem;
map<ll,ll>m,s;
ll dp(int msk)
{
    if(msk==(1<<n)-1)return 1;
    if(mem.count(msk))return mem[msk];
    ll ret=0;
    for(int i=0;i<n;i++)
    {
        if((msk&(1<<i))==0)
            if((1<<m[s[i]/2])&msk)ret+=dp(msk|(1<<i));
    }
    return mem[msk]=ret;
}


class ConstructBST{
public:
    long long numInputs(vector <int> tree){
       n=tree.size();
       int k=0;
       for(int i=0;i<n;i++)
       {
         a[i]=tree[i];
         m[a[i]]=i;
         s[i]=a[i];
         if(a[i]==1)k|=(1<<i);
       }
       ll ans=dp(k);
       return ans;
    }

};
