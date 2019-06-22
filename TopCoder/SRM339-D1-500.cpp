#include<queue>
#include<map>
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
//#define var(x) ((x)<<1)
//#define nvar(x) ((x)^1)
const int N=100000,M=100000;
int n,g;
double mem[55][55][1005];

double dp(int i,int t,int sum,int p)
{
    if(sum>=g) return 1.0;
    if((1<<t)>sum) return 0.0;
    if(i>n) return 0.0;
    double&ret=mem[i][t][sum];
    if(ret==ret)return ret;
    ret=0;
    ret+=dp(i+1,0,sum+(1<<t),p)*p/100.0;
    ret+=dp(i+1,t+1,sum-(1<<t),p)*(1.0-p/100.0);
    return ret;
}
class TestBettingStrategy
{
public:
    double winProbability(int initSum, int goalSum, int rounds, int prob)
    {
        memset(mem,-1,sizeof mem);
        n=rounds;
        g=goalSum;
        double ans=dp(1,0,initSum,prob);
        return ans;
    }
};
