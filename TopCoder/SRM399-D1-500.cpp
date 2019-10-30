/*
   we need to know the number of bits that equal 1 in a , b , and c .
   then try all possible combination  using the normal binary addition .
*/
#pragma GCC optimize("O3")
#include<queue>
#include <cmath>
#include <complex>
#include<map>
#include <string>
#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <stdio.h>
#include<bits/stdc++.h>


/*
#define x real()
#define y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))
*/

//#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);
#define NOT(x) (1^x)

const double PI  = acos(-1.0);
using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
typedef complex<double> point;

//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//const int N=500009,M=1000000;
const double EPS= 1e-9,eps=-1e9;
//const int N =300005;
ll mem[32][32][32][35][2];
int mx,k;
ll dp(int a,int b,int c,int i,int rem)
{
    if(a<0||b<0||c<0)return 1e17;
    if(a==0&&b==0&&rem==0)
    {
        if(c)return 1e17;
        return 0;
    }
    if(i==k) return 1e17;
    ll&ret=mem[a][b][c][i][rem];
    if(~ret)return ret;
    ret=1e17;
    int val,nrem;

    val=(rem+1)%2;
    nrem=(rem+1)/2;
    ret=min(ret,dp(a,b-1,(val>0?c-1:c),i+1,nrem)+val*((ll)1<<i));

    val=(rem+1)%2;
    nrem=(rem+1)/2;
    ret=min(ret,dp(a-1,b,(val>0?c-1:c),i+1,nrem)+val*((ll)1<<i));

    val=rem%2;
    nrem=rem/2;
    ret=min(ret,dp(a,b,(val>0?c-1:c),i+1,nrem)+val*((ll)1<<i));

    val=(rem+2)%2;
    nrem=(rem+2)/2;
    ret=min(ret,dp(a-1,b-1,(val>0?c-1:c),i+1,nrem)+val*((ll)1<<i));

    return ret;

}

class BinarySum{
public:
    int rearrange(int a, int b, int c){
        mx=max(a,b);
        mx=max(mx,c);
        while(mx)
        {
          k++;
          mx/=2;
        }
        memset(mem,-1,sizeof mem);
        ll ans=dp(__builtin_popcount(a),__builtin_popcount(b),__builtin_popcount(c),0,0);
        if(ans>=1e17)return -1;
        return ans;

    }
};
