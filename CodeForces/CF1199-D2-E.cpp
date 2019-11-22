//https://codeforces.com/blog/entry/68812
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
const int N = 1006 + 3, M = 5e4 + 3;


int n,m,ck[2000009];

 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
//input;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        int u,v;
        vector<int>k;
        memset(ck,0,(n*3+5)*sizeof ck[0]);
        forr(i,1,m)
        {
            scanf("%d %d",&u,&v);
            if(!ck[u]&&!ck[v])
            {
                k.push_back(i);
                ck[u]=1;
                ck[v]=1;
            }
        }
        if(k.size()>=n)
        {
            cout<<"Matching"<<endl;
            for(int i=0;i<n;i++)cout<<k[i]<<" ";
        }
        else
        {
            cout<<"IndSet"<<endl;
            int c=n;
            forr(i,1,n*3)
            {
                if(c&&!ck[i])
                {
                    cout<<i<<" ";
                    c--;
                }
            }
        }
        cout<<endl;
    }




return 0;
}
