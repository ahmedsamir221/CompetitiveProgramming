/*
   we can use this equation  y = m*x + c
   we can use map it's key is m and c , it's value is set of integer .
   so we can get m and c between each two points and add this points to the map .
   the answer is line with max points .
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
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep ,cos
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel , sin
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
const double EPS= 1e-8;
int t,n,x[800],y[800],cas;
string s;
 main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("ahmed.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
//printf("%s, ",name[k[i]].c_str());  printf of string
//priority_queue<ll,vector<ll>,greater<ll>>y;
input;

cin>>t;
getline(cin,s);
getline(cin,s);
while(t--)
{
    int n=0,u,v;
    double c;
    while(getline(cin,s))
    {
        if((int)s.size()==0)break;
        stringstream f;
        f<<s;
        f>>u>>v;
        x[++n]=u,y[n]=v;
    }
    map<pair<pair<int,int>,int>,set<int>>m;
    forr(i,2,n)
    {
        forr(j,1,i-1)
        {
            u=x[i]-x[j];
            v=y[i]-y[j];
            if(u==0){
                m[{{1e9,1e9},x[i]}].insert(i);
                m[{{1e9,1e9},x[i]}].insert(j);
            }
            else{
            int g=__gcd(u,v);
            u/=g;
            v/=g;
            c=y[i]*1.0-(v*1.0/u)*1.0*x[i];
            c*=100;
            m[{{v,u},(int)(c+EPS)}].insert(i);
            m[{{v,u},(int)(c+EPS)}].insert(j);
            }
        }
    }
    int ans=0;
    for(auto p:m)ans=max(ans,(int)p.S.size());
    if(cas++)cout<<endl;
    cout<<ans<<endl;
}


return 0;
}
