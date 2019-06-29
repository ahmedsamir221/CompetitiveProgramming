/*
   we can check if any corner point of one of them inside the other
   the remaining case is

                            $$$$$$
                            $    $
                            $    $
                        ***************
                        *   $    $    *
                        *   $    $    *
                        ***************
                            $    $
                            $    $
                            $$$$$$
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
pair<int,int>a[3],b[3],ansl,ansu;

bool check(pair<int,int> A, pair<int,int> B, pair<int,int> C,int t)
{
    if(!(C.F>=A.F&&C.F<=B.F&&C.S>=A.S&&C.S<=B.S))return 0;
    if(C.F==a[t].F)
    {
        if(C.S==a[t].S)
        {
            ansl.F=C.F;
            ansl.S=C.S;
            ansu.F=min(b[t].F,B.F);
            ansu.S=min(b[t].S,B.S);
        }
        else
        {
            ansl.F=C.F;
            ansl.S=max(a[t].S,A.S);
            ansu.F=min(b[t].F,B.F);
            ansu.S=C.S;
        }
    }
    else
    {
        if(C.S==a[t].S)
        {
            ansl.F=max(a[t].F,A.F);
            ansl.S=C.S;
            ansu.F=C.F;
            ansu.S=min(b[t].S,B.S);
        }
        else
        {
            ansl.F=max(a[t].F,A.F);
            ansl.S=max(a[t].S,A.S);
            ansu.F=C.F;
            ansu.S=C.S;
        }
    }
    if(ansu.F-ansl.F==0||ansu.S-ansl.S==0)return 0;
    return 1;
}
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
int t,cas=0;
cin>>t;
while(t--)
{
    if(cas)cout<<endl;
    cas++;
    cin>>a[1].F>>a[1].S>>b[1].F>>b[1].S;
    cin>>a[2].F>>a[2].S>>b[2].F>>b[2].S;
    if(check(a[2],b[2],{a[1].F,a[1].S},1))cout<<ansl.F<<" "<<ansl.S<<" "<<ansu.F<<" "<<ansu.S<<endl;
    else if(check(a[2],b[2],{a[1].F,b[1].S},1))cout<<ansl.F<<" "<<ansl.S<<" "<<ansu.F<<" "<<ansu.S<<endl;
    else if(check(a[2],b[2],{b[1].F,a[1].S},1))cout<<ansl.F<<" "<<ansl.S<<" "<<ansu.F<<" "<<ansu.S<<endl;
    else if(check(a[2],b[2],{b[1].F,b[1].S},1))cout<<ansl.F<<" "<<ansl.S<<" "<<ansu.F<<" "<<ansu.S<<endl;
    else if(check(a[1],b[1],{a[2].F,a[2].S},2))cout<<ansl.F<<" "<<ansl.S<<" "<<ansu.F<<" "<<ansu.S<<endl;
    else if(check(a[1],b[1],{a[2].F,b[2].S},2))cout<<ansl.F<<" "<<ansl.S<<" "<<ansu.F<<" "<<ansu.S<<endl;
    else if(check(a[1],b[1],{b[2].F,a[2].S},2))cout<<ansl.F<<" "<<ansl.S<<" "<<ansu.F<<" "<<ansu.S<<endl;
    else if(check(a[1],b[1],{b[2].F,b[2].S},2))cout<<ansl.F<<" "<<ansl.S<<" "<<ansu.F<<" "<<ansu.S<<endl;
    else if(a[1].F>=a[2].F&&b[1].F<=b[2].F&&a[2].S>=a[1].S&&b[2].S<=b[1].S)cout<<max(a[1].F,a[2].F)<<" "<<max(a[1].S,a[2].S)<<" "<<min(b[1].F,b[2].F)<<" "<<min(b[1].S,b[2].S)<<endl;
    else if(a[2].F>=a[1].F&&b[2].F<=b[1].F&&a[1].S>=a[2].S&&b[1].S<=b[2].S)cout<<max(a[1].F,a[2].F)<<" "<<max(a[1].S,a[2].S)<<" "<<min(b[1].F,b[2].F)<<" "<<min(b[1].S,b[2].S)<<endl;
    else cout<<"No Overlap"<<endl;
}

return 0;
}
