//https://codeforces.com/blog/entry/65365
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
const int N=50009,M=1000000;
string in,s[3],t[3],out;
int n,p[N],vis[N];
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;
     cin>>in;
     n=in.size();
     for(int i=0;i<3;i++)
     s[i].resize(n),t[i].resize(n);

     int c=0;
     for(int i=0;i<26;i++)
     for(int j=0;j<26;j++)
     for(int k=0;k<26;k++)
     {
         if(c<n)
         {
             s[0][c]='a'+i;
             s[1][c]='a'+j;
             s[2][c]='a'+k;
             c++;
         }
     }

     for(int i=0;i<3;i++)
     {
         cout<<"? "<<s[i]<<endl;
         fflush(stdout);
         cin>>t[i];
     }

     for(int i=0;i<n;i++)
     {
         for(int j=0;j<n;j++)
         {
             if(s[0][i]==t[0][j]&&s[1][i]==t[1][j]&&s[2][i]==t[2][j])
             {
                 p[j]=i;
             }
         }
     }
     out.resize(n);
     for(int i=0;i<n;i++)out[p[i]]=in[i];
     cout<<"! "<<out<<endl;
     fflush(stdout);


return 0;
}
