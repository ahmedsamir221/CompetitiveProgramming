//https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/UVA/588.cpp
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



#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);


const double PI  = acos(-1.0);
using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
typedef complex<double> point;

//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
const int N=300007,M=1000000;
const double EPS= 1e-9,eps=-1e9;

pair<int,int>t[104];

 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;
int cas=0,n;

while(cin>>n,n)
{
    for(int i=0;i<n;i++)
        cin>>t[i].F>>t[i].S;
    int l=-2e9,r=2e9,up=2e9,down=-2e9;
    for(int i=0;i<n;i++)
    {
        int a=i,b=(i+1)%n,c=(i+2)%n,d=(i-1+n)%n;
        if(t[a].F==t[b].F)
        {
            if((t[c].F>t[a].F&&t[d].F>t[a].F)||(t[c].F<t[a].F&&t[d].F<t[a].F))
            {
                up=min(up,max(t[a].S,t[b].S));
                down=max(down,min(t[a].S,t[b].S));
            }
        }
        else
        {
            if((t[c].S>t[a].S&&t[d].S>t[a].S)||(t[c].S<t[a].S&&t[d].S<t[a].S))
            {
                r=min(r,max(t[a].F,t[b].F));
                l=max(l,min(t[a].F,t[b].F));
            }
        }
    }
    cout<<"Floor #"<<++cas<<endl;
    if(l>r||down>up)cout<<"Surveillance is impossible."<<endl;
    else cout<<"Surveillance is possible."<<endl;
    cout<<endl;

}



return 0;
}
