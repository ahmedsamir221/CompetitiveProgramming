
#include <iostream>
#include<vector>
#include<algorithm>
//#include <cmath>
//#include <complex>
#include<queue>
#include<map>
#include <string>
#include<bits/stdc++.h>
#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);
//#define x real()
//#define y imag()
using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
//typedef complex<double> point;
//template<typename T>T gcd(T x, T y) { if(y == 0)return x; else return gcd(y, x%y); }
//typedef bitset<30> mask;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//const double PI = acos(-1.0);
//const double EPS = 1e-9;
//typedef complex<double> point;
long double x,y,z,ans;
int e=0;
string a[9]={"x^y^z","x^z^y","(x^y)^z","y^x^z","y^z^x","(y^x)^z","z^x^y","z^y^x","(z^x)^y"};
int main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
cin>>x>>y>>z;

ans=pow(y,z)*log(x);

if(pow(z,y)*log(x)>ans)
ans=pow(z,y)*log(x),e=1;


if(z*y*log(x)>ans)
ans=z*y*log(x),e=2;

if(pow(x,z)*log(y)>ans)
ans=pow(x,z)*log(y),e=3;

if(pow(z,x)*log(y)>ans)
ans=pow(z,x)*log(y),e=4;


if(z*x*log(y)>ans)
ans=z*x*log(y),e=5;


if(pow(x,y)*log(z)>ans)
ans=pow(x,y)*log(z),e=6;

if(pow(y,x)*log(z)>ans)
ans=pow(y,x)*log(z),e=7;

if(y*x*log(z)>ans)
ans=y*x*log(z),e=8;


cout<<a[e];
return 0;
}
