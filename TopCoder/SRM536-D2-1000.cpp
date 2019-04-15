/*
   first we need to sort the all elements then use dp ;
   we will begin from the end and each time will try to get at least (K-1) element then recurs to 
   the remaining elements
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
ll n,m,a[55],sum[55];
double mem[55];
double dp(ll i)
{
    if(i<m)return sum[i];
    double&ret=mem[i];
    if(ret==ret)return ret;
    ret=sum[i]*1.0/i;
    for(ll j=m;j<=i-m+1;j++)
    {
        double v=dp(j);
        double g=sum[i]-sum[j]+v;
        g/=((i-j+1)*1.0);
        ret=max(ret,g);
    }
    return ret;
}
class MergersDivTwo{
public:
    double findMaximum(vector <int> revenues, int k)
    {
        n=(int)revenues.size();
        forr(i,1,n)a[i]=revenues[i-1];
        sort(a+1,a+1+n);
        forr(i,1,n)
        sum[i]=a[i]+sum[i-1];
        memset(mem,-1,sizeof mem);
        m=k;
        return dp(n);
    }
};
