/*
    first we need to get the height of trapezium and we can do that by using binary search .
    then use another binary search to get split point of the trapezium  .
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
const int N=100007,M=1000000;
const double EPS= 1e-9,eps=-1e9;




 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
//input;

int t,cas=0;
cin>>t;
while(t--)
{
    int ab,dc,ad,bc;
    cin>>ab>>dc>>ad>>bc;
    point a(0,0);
    point b(ab,0);
    point c(0,0);
    point d(0,0);

    double l=0,r=ad,mid,g;
    forr(i,1,500)
    {
        mid=(l+r)/2.0;
        g=sqrt(pow(ad,2)-pow(mid,2));
        d={mid,g};
        c={mid+dc,g};
       // cout<<fixed<<setprecision(6)<<mid<<" "<<length(c-b)<<endl;
        if(length(c-b)>(double)bc)l=mid;
        else r=mid;
    }
  //  cout<<fixed<<setprecision(6)<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    double lftarea=0.5*g*mid;
    double rtarea=0.5*(ab*1.0-mid-dc)*g;
    double h=g;
  //  cout<<fixed<<setprecision(6)<<h<<" "<<rtarea<<endl;
    l=0,r=h;
    forr(i,1,1000)
    {
        mid=(l+r)/2.0;
        double uparea=lftarea*mid*mid/(h*h)+dc*mid+rtarea*mid*mid/(h*h);
        double downarea=lftarea+h*dc+rtarea-uparea;
        if(uparea<downarea)l=mid;
        else r=mid;
    }
   // mid=h-mid;
    cout<<"Land #"<<++cas<<": "<<fixed<<setprecision(6)<<ad*1.0-(mid*ad/h)<<" "<<bc*1.0-(mid*bc/h)<<endl;
  //cout<<fixed<<setprecision(6)<<mid<<" "<<h<<endl;


}
return 0;
}
