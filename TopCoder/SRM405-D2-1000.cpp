/*
  we can use dp to get the answer , out state will be the current char and number of remaining char that i did not use
  till now, and each step i will try to add new char or use one of remaining chars
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
#define var(x) ((x)<<1)
#define nvar(x) ((x)^1)
const int N=2e5+5,M=6e5+5;
string ans;
int mem[110][140],c[27],t;
int dp(int i,int p ,int l)
{
    if(p+i-1>l)return 1e8;
    if(i>l)
    {
        if(p==0)return 0;
        else return 1e8;
    }
    int&ret=mem[i][p];
    if(~ret)return ret;

    int c1=dp(i+1,p+i-1,l)+1;
    int c2=1e8;
    if(p)c2=dp(i+1,p-1,l);
    if(c2<=c1)return ret=c2;
    else return ret=c1;
}


void bulid(int i,int p ,int l)
{
    if(i>l)return ;
    if(dp(i,p,l)==dp(i+1,p-1,l))
    {
        ans[i-1]='.';
        bulid(i+1,p-1,l);
    }
    else
    {
        c[t]=i-1;
        ans[i-1]=(char)('A'+t++);
        bulid(i+1,p+i-1,l);
    }
}

class IdealString{
public:
    string construct(int length){
        memset(mem,-1,sizeof mem);
        int g=dp(1,0,length);
        if(g>=1e8)return "";
        ans.resize(length);
        bulid(1,0,length);
        forr(i,0,25)
        {
            forr(j,0,ans.size()-1)
            {
                if(c[i]&&ans[j]=='.')ans[j]=(char)('A'+i),c[i]--;
            }
        }
         return ans;
    }
};
