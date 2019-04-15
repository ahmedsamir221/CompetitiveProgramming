/*
    we will use classic dp to count the number of ways to construct the road;
    to check if number of ways to pass the road with out use wet segments ,we need to find 
    consecutive dry segments with even number of ways ,and to check that there is
    a pattern of number of ways in consecutive dry segments -->> odd odd even and so on ... , in middle segments ;
    odd even odd and so on ........ , in start and end segments;     
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
ll m=555555555,n,mem[558][558][3][2],k;
int dp(int i=2,int c=0,int p=0,int ck=0)
{
    if(i==n)
    {
        if(ck&&c==k)return 1;
        else return 0;
    }
    ll&ret=mem[i][c][p][ck];
    if(~ret)return ret;
    if(c==k)
    {
        if((n-i)%3==2)return ret=dp(n,c,0,1)%m;
        else return ret=dp(n,c,0,ck)%m;
    }
    ll c1=dp(i+1,c,(p+1)%3,ck)%m;
    ll c2=0;
    if(c==0)
    {
        if(p==2)c2=dp(i+1,c+1,0,1)%m;
        else c2=dp(i+1,c+1,0,ck)%m;
    }
    else
    {
        if(p==0)c2=dp(i+1,c+1,0,1)%m;
        else c2=dp(i+1,c+1,0,ck)%m;
    }
    return ret=(c1+c2)%m;
}

class MuddyRoad2{
public:
    int theCount(int N, int muddyCount)
    {
        n=N;
        k=muddyCount;
        if(k==0)
        {
            if(n%3==0)return 1;
            else return 0;
        }
        memset(mem,-1,sizeof mem);
        return (dp()+m)%m;
    }
};
