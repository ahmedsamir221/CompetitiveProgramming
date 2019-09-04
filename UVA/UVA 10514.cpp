//https://github.com/MohamedNabil97/CompetitiveProgramming/blob/master/UVA/10514.cpp
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


#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);


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

const double PI  = acos(-1.0);
using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
typedef complex<double> point;

//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
const int N=100007,M=1000000;
const double EPS= 1e-9;

int n,r1,r2;
vector<point>pol[N];

double dcmp( double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }

double dist_point_stline(point p0,point p1, point p){
    point w=vec(p0,p);
    point vl=vec(p0,p1);
    double b=dp(w,vl)/dp(vl,vl);
    point pb=p0+b*vl;
    return length(pb-p);
}
double dist_point_lineseg(point p0,point p1 ,point p){
    point w=vec(p0,p);
    point vl=vec(p0,p1);
    double b=dp(w,vl)/dp(vl,vl);
    if(dcmp(b,0)==-1 || dcmp(b,1)==1){
        return min(length(p-p0),length(p-p1));
    }
      point pb=p0+b*vl;
    return length(pb-p);

}
double dist_lineseg_lineseg(point p0,point p1 ,point p2,point p3){
    double a=dist_point_lineseg( p0, p1,  p2);
     double b=dist_point_lineseg( p0, p1,  p3);
      double c=dist_point_lineseg( p2, p3,  p0);
       double d=dist_point_lineseg( p2, p3,  p1);
    return min(min(a,b),min(c,d));

}

double dist_polygon_polygon(vector <point> p1, vector<point> p2){
    double dist=1e18;
    for(int i=1; i<p1.size(); i++){
        for(int j=1; j<p2.size(); j++){
            dist=min(dist,dist_lineseg_lineseg(p1[i],p1[i-1],p2[j],p2[j-1]));
        }
    }
    return dist;

}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;
int t;
cin>>t;
while(t--)
{
    cin>>r1>>r2>>n;
    int X,Y;
    vector<point>blank1,blank2;
    forr(i,1,r1)
    {
        cin>>X>>Y;
        point a(X,Y);
        blank1.push_back(a);
    }
    forr(i,1,r2)
    {
        cin>>X>>Y;
        point a(X,Y);
        blank2.push_back(a);
    }
    int m;
    forr(i,1,n)
    {
        cin>>m;
        pol[i].clear();
        forr(j,1,m)
        {
            cin>>X>>Y;
            point a(X,Y);
            pol[i].push_back(a);
        }
        pol[i].push_back(pol[i][0]);
    }

    double adj[15][15];
    forr(i,0,14)forr(j,0,14)adj[i][j]=1e18;
    forr(i,0,14)adj[i][i]=0;

    forr(i,1,n)
    {
        double dis=dist_polygon_polygon(blank1,pol[i]);
        adj[0][i]=dis;
        adj[i][0]=dis;
    }
    forr(i,1,n)
    {
        double dis=dist_polygon_polygon(blank2,pol[i]);
        adj[n+1][i]=dis;
        adj[i][n+1]=dis;
    }

    forr(i,1,n)
    {
        forr(j,i+1,n)
        {
            double dis=dist_polygon_polygon(pol[i],pol[j]);
            adj[i][j]=dis;
            adj[j][i]=dis;
        }
    }
    double dis=dist_polygon_polygon(blank1,blank2);
    adj[0][n+1]=dis;
    adj[n+1][0]=dis;

    forr(k,0,n+1)forr(i,0,n+1)forr(j,0,n+1)adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
    cout<<fixed<<setprecision(3)<<adj[0][n+1]<<endl;

}

return 0;
}
