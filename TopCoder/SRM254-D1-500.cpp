/*
   we will use normal dp and try to select the best position .
   to know the delay of our selection to detect the best one ,we will make our return value vector of int
   which tell us the order of filling of the positions .
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
const int N =100005;
string s;
int n;
vector<int> mem[1<<16];
vector<int>mp;
vector<int> dp(int msk)
{
    if(msk==(1<<n)-1)return mp;
    vector<int>&ret=mem[msk];
    if(ret.size())return ret;
    int mx=-1;
    vector<int>t;
    for(int i=0;i<n;i++)
    {
        if(msk&(1<<i))continue;
        int g=0;
        vector<int> k=dp(msk|(1<<i));

        for(int j=k.size()-1,c=1;j>-1;j--,c++)
        if(k[j]==i-1||k[j]==i+1)g=c;

        if(i==0)g=20;
        else if(i==n-1)g=19;

        if(g>mx)
        {
            mx=g;
            t=k;
            t.push_back(i);
        }
    }
    return ret=t;
}

class Piglets{
public:
    int choose(string trough){
    s=trough;
    n=s.size();
    int msk=0;
    for(int i=0;i<n;i++)
        if(s[i]=='p')msk|=(1<<i);
    vector<int>ans=dp(msk);
    if(ans.size())return ans[(int)ans.size()-1];
    else return -1;

    }
};
