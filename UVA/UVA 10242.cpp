/*
   the input gives four point two of them are the same , so we can get the mid point of the other two points ,
   then make a vector from that mid point to the common point from the input ,then multiply that vector with 2 .
   and the answer will be the end point of the vector

*/
#include<queue>
#include <cmath>
#include <complex>
#include<map>
#include <string>
#include<iostream>
#include<bits/stdc++.h>


#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);


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


using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
typedef complex<double> point;
//template<typename T>T gcd(T x, T y) { if(y == 0)return x; else return gcd(y, x%y); }
//typedef bitset<30> mask;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//#define var(x) ((x)<<1)
//#define nvar(x) ((x)^1)
const int N=100000,M=100000;
const double EPS=1e-8;
pdd as,ae,bs,be;
 main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
//printf("%s, ",name[k[i]].c_str());  printf of string
//priority_queue<ll,vector<ll>,greater<ll>>y;
//input;
while(cin>>as.F>>as.S>>ae.F>>ae.S>>bs.F>>bs.S>>be.F>>be.S)
{
  point As(as.F,as.S);
  point Ae(ae.F,ae.S);
  point Bs(bs.F,bs.S);
  point Be(be.F,be.S);

  if(Ae==Be) swap(As,Ae),swap(Bs,Be);
  else if(As==Be) swap(Bs,Be);
  else if(Bs==Ae) swap(As,Ae);
  point mid,ans;
  mid=Ae+Be;
  mid/=2;
  mid-=As;
  mid*=2;
  ans = mid + As;
  cout<<fixed<<setprecision(3)<<ans.X<<" "<<fixed<<setprecision(3)<<ans.Y<<endl;

}
return 0;
}
