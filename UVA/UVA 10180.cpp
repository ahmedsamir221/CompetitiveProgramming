/*
    if there are no intersect between the segment and the circle the answer will be the length of the segment .
    else we need to get the length of tangents from the tow point and we can do that  by pythagorean theorem
    then get the length of the arc between every two tangents .
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

#define X real()
#define Y imag()
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
const int N=500007,M=1000000;
const double EPS= 1e-9;

int t;
double dis(double a,double b,double c,double d)
{
    return sqrt(pow(a-c,2)+pow(b-d,2));
}

int dcmp (double a, double b){
    return fabs(a-b) <= EPS ? 0 : a < b ? -1 : 1 ;
}

double getAng(point &a, point &b, point &c) // find angle abc, anticlock bc to ba
{
    double ang = angle( vec(b, c)) - angle( vec(b, a));
    if(dcmp(ang, 0) < 0)
    	ang+=2*PI;
    return ang;
}


bool intersectLineCircle(point p0, point p1, point C, double r) {
    double a = dp(p1-p0, p1-p0), b = 2*dp(p1-p0, p0-C),
           c = dp(p0-C, p0-C) - r*r;
    double f = b*b - 4*a*c;

    vector<point> v;
    if( dcmp(f, 0) >= 0) {
	    if( dcmp(f, 0) == 0)	f = 0;
	    double t1 =(-b + sqrt(f))/(2*a);
	    double t2 =(-b - sqrt(f))/(2*a);
	    if(t1 >= -EPS && t1 <= 1+EPS)v.push_back( p0 + t1*(p1-p0) );
	    if( dcmp(f, 0) != 0&& t2 >= -EPS && t2 <= 1+EPS)	v.push_back( p0 + t2*(p1-p0) );
    }
    if((int)v.size()>1)return 1;
    return 0;
}

 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;

cin>>t;
while(t--)
{
    double u,v,r;
    cin>>u>>v;
    point a(u,v);
    cin>>u>>v;
    point b(u,v);
    cin>>r;
    point c(0,0);

    if(a.X>b.X)swap(a,b);
    else if(a.X==b.X&&a.Y>b.Y)swap(a,b);

    double ans1=length(a-b);

    double ans2=sqrt(pow(length(a-c),2)-r*r);
    ans2+=sqrt(pow(length(b-c),2)-r*r);
    double an=getAng(a,c,b);
    an-=acos(r/length(a-c));
    an-=acos(r/length(b-c));
    ans2+=an*r;

    double ans3=sqrt(pow(length(a-c),2)-r*r);
    ans3+=sqrt(pow(length(b-c),2)-r*r);
    an=getAng(b,c,a);
    an-=acos(r/length(a-c));
    an-=acos(r/length(b-c));
    ans3+=an*r;

    cout<<fixed<<setprecision(3);
   // cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
    if(intersectLineCircle(a,b,c,r))cout<<min(ans2,ans3)<<endl;
    else cout<<ans1<<endl;
}





return 0;
}
