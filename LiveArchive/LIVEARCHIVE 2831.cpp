// we just need to try all possible cuts and get the best
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

pair<int,int>a[4];


double polygonArea(vector<point> &p) {
    double area = 0;
    int n = p.size();
    for(int i = 0; i < n;i++)
		area += p[i].x * p[(i+1)%n].y - p[i].y * p[(i+1)%n].x;
    return fabs(area) /2;
}

 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;
int cas=0;

while(1)
{
    int ck=1;
    forr(i,0,3)
    {
        cin>>a[i].F>>a[i].S;
        if(a[i].F!=0||a[i].S!=0)ck=0;
    }
    if(ck)break;
    vector<point>k;
    forr(i,0,3)
    {
        point u(a[i].F,a[i].S);
        point v(a[(i+1)%4].F,a[(i+1)%4].S);
        point m=u+v;
        m/=2;
        k.push_back(u);
        k.push_back(m);
    }
    double totarea=polygonArea(k);
    double area1=0,area2=0,df=1e18;
    for(int i=0;i<8;i++)
    {
        int c=0;
        if(i%2==0)c=1;
        for(int j=(i+2+c)%8;j!=(i-1-c+8)%8;j=(j+1)%8)
        {
            vector<point>t;
            t.push_back({k[i].x,k[i].y});
            for(int e=j;e!=i;e=(e+1)%8)
            t.push_back({k[e].x,k[e].y});
            double area=polygonArea(t);
            if(fabs(totarea-2*area)<df)
            {
                df=fabs(totarea-2*area);
                area1=area;
                area2=fabs(totarea-area);
            }

        }
    }
    cout<<"Cake "<<++cas<<": "<<fixed<<setprecision(3)<<min(area1,area2)<<" "<<max(area1,area2)<<endl;
}



return 0;
}
